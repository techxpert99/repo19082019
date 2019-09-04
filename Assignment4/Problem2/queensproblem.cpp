/**
  * @file queensproblem.cpp
  * @author Ritik Jain
  * @date 29/08/2019
  * @brief The Queens Problem Solver
  */

#include "queensproblem.h"

Map::Map(unsigned int N)
{
    this->N = N;
    qp = 0;
    loc = new unsigned int[N];
}

Solution::Solution(Map *map)
{
    N = map->N;
    loc = new unsigned int[N];
    unsigned int j;
    for(j=0; j < N; j++)
        loc[j] = map->loc[j];
}

QueensProblem::QueensProblem(unsigned int N)
{
    sp = 0;
    this->N = N;
}

Map::~Map()
{
delete [] loc;
}

Solution::~Solution()
{
delete [] loc;
}

QueensProblem::~QueensProblem()
{
delete [] slns;
}

void Map::addQueen(unsigned int x)
{
if(x>=N) return;

loc[qp++] = x;
}

void Map::subQueen()
{
if(!qp) return;

loc[qp-1] = 0;
qp--;
}

void Map::seek(unsigned int qp)
{
if(qp>=N) return;

this->qp = qp;
}

int Map::peek(unsigned int lev)
{
    if(lev>=qp) return -1;
    return loc[lev];
}

Solution* Solution::getSolution(Map *map)
{
    if(!map || map->qp < map->N) return nullptr;

    return new Solution(map);
}

bool QueensProblem::isConflict(Map *map, unsigned int x, unsigned int y)
{
    unsigned int j;
    for(j=0; j < map->qp; j++)
        if(x==map->loc[j] || y==j || (x-y==map->loc[j]-j) || (x+y==map->loc[j]+j))
            return 1;

    return 0;
}

bool QueensProblem::addSolution(Map *map)
{
    Solution *sln = Solution::getSolution(map);

    if(!sln) return 0;

    if(slns)
    {
        Solution **_slns = slns;
        slns = new Solution*[++sp];
        unsigned int j;
        for(j=0; j < sp-1; j++)
            slns[j] = _slns[j];
        slns[sp-1] = sln;
    }
    else {
        slns = new Solution*;
        slns[sp++] = sln;
    }

    return 1;
}

void QueensProblem::genSolution(Map *map)
{
    if(addSolution(map))
        return;

    unsigned int qp = map->qp;
    unsigned int j;

    for(j=0; j < map->N; j++)
    {
        if(!isConflict(map, j, map->qp))
        {
            map->addQueen(j);
            genSolution(map);
            map->seek(qp);
        }
    }
}

Solution **QueensProblem::getSolutions()
{
    return slns;
}

void QueensProblem::solve()
{
    Map* map = new Map(N);
    Solution* _sln = singleSolution(map);

    if(!_sln)
        return;

    unsigned int *sln = _sln->sln();

    map->seek(0);
    bool *val = new bool[N];

    unsigned int j;

    for(j=0;j<N;j++)
        val[j]=1;

    genSolutionv2(sln,map, val);

    delete [] val;
    delete map;
}

unsigned int QueensProblem::countSolutions()
{
    return sp;
}

Solution* QueensProblem::singleSolution(Map *map)
{
    Solution *sln = nullptr;

    if((sln = Solution::getSolution(map)))
        return sln;

    unsigned int qp = map->qp;
    unsigned int j;
    for(j=0; j<N;j++)
    {
        if(!isConflict(map,j,qp))
        {
            map->addQueen(j);
            sln = singleSolution(map);
            if(sln)
                return sln;
            map->seek(qp);
        }
    }

    return sln;
}

void QueensProblem::genSolutionv2(unsigned int *sln, Map *map, bool* val)
{
    if(addSolution(map)) return;

    unsigned int qp = map->qp;
    unsigned int j;

    for(j=0; j < N; j++)
    {
        if(val[j]&&!isConflict(map, sln[j],qp))
        {

            map->addQueen(sln[j]);
            val[j] = 0;
            genSolutionv2(sln, map, val);
            map->seek(qp);
            val[j] = 1;
        }
    }
}
