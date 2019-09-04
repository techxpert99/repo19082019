/**
  * @file queensproblem.h
  * @author Ritik Jain
  * @date 29/08/2019
  * @brief The Queens Problem Solver
  */

#ifndef QUEENSPROBLEM_H
#define QUEENSPROBLEM_H

/**
 * @brief The Map class
 * @author Ritik Jain
 * @date 29/08/2019
 * @brief A map is an arrangement of N or less queens for an NxN Board
 *
 */
class Map
{
public:

    /**
     * @param N  The Board-Number for the Map
     * @author Ritik Jain
     * @date 29/08/2019
     * @brief Creates and initializes the map
     */
    Map(unsigned int N);

    ~Map();

    /**
     * @brief Adds a queen to the map with the mentioned abscissa
     * @author Ritik Jain
     * @date 29/08/2019
     * @param x  The abscissa of the queen to be added
     */
    void addQueen(unsigned int x);

    /**
     * @brief Removes the queen at top by decrementing the queen pointer
     * @author Ritik Jain
     * @date 29/08/2019
     */
    void subQueen();

    /**
     * @brief Seeks the queen pointer of the map to a given index ( qp )
     * @author Ritik Jain
     * @date 29/08/2019
     * @param qp  The new queen pointer
     */
    void seek(unsigned int qp);

    /**
     * @brief Peeks at the Queen of a Particular Level
     * @author Ritik Jain
     * @date 29/08/2019
     * @param lev  The level to peek  at
     * @returns The abscissa of the queen ; Returns -1 if there is no queen
     */
    int peek(unsigned int lev);

private:

    //The map-number N : (Board is NxN)
    unsigned int N;

    //Th locations of the stored queens [ (x,y) ; (x,y) ; ... ]
    unsigned int* loc = nullptr;

    //The Queen Pointer : (0,1,2,..)
    unsigned int qp;

    //Friend Class QueensProblem
    friend class QueensProblem;

    //Friend Class Solution
    friend class Solution;
};

/**
 * @author Ritik Jain
 * @date 29/08/2019
 * @brief The class for storing solutions for complete maps
 */
class Solution
{
public:

    /**
     * @author Ritik Jain
     * @date 29/08/2019
     * @brief Obtains the solution to the map if it is complete
     * @param map  The map for which the solution is to be obtained
     * @return Returns the Solution for the given map; Returns null if the map is not complete
     */
    static Solution *getSolution(Map *map);

    ~Solution();

    /**
      * @author Ritik Jain
      * @date 29/08/2019
      * @brief Used to get the solution
      * @return The solution
      */
    unsigned int* sln()
    {
     return loc;
    }

private:

    /**
     * @author Ritik Jain
     * @date 29/08/2019
     * @brief Creates a solution out of a map and initializes it
     * @param map  The map of which the solution is to be made
     */
    Solution(Map *map);

    //The Board-Number : N (Board is NxN)
    unsigned int N;

    //The locations of the stored queens [ (x,y) ; (x,y) ; ... ]
    unsigned int *loc= nullptr;

    //Friend class QueensProblem
    friend class QueensProblem;

    //Friend class Map
    friend class Map;
};

/**
 * @author Ritik Jain
 * @date 29/08/2019
 * @brief The class for solving N-Queen Problems
 */
class QueensProblem
{
public:

    /**
     * @author Ritik Jain
     * @date 29/08/2019
     * @param N  The Board-Number for the given problem
     * @brief Initializes the Queens Problem
     */
    QueensProblem(unsigned int N);

    ~QueensProblem();

    /**
     * @author Ritik Jain
     * @date 29/08/2019
     * @brief Solves the Queens Problem for a given Board Number and stores the Solutions
     */
    void solve();

    /**
     * @author Ritik Jain
     * @date 29/08/2019
     * @brief Used to get the solutions of this Queens Problem
     * @return Returns the Solutions to this Queen Problem
     */
    Solution** getSolutions();

    /**
     * @author Ritik Jain
     * @date 29/08/2019
     * @brief Used to get the number of solutions of this Queens Problem
     * @return Returns the number of Solutions to this Queen Problem
     */
    unsigned int countSolutions();

    /**
     * @brief Generates and stores valid solutions to the queens problem given an initial map O(N!xN^2) [ver 2]
     * @author Ritik Jain
     * @date 29/08/2019
     * @param sln  A previous starting solution (single solution)
     * @param map  A starting map to progress
     * @param val  The valid rows for a particular iteration
     */
    void genSolutionv2(unsigned int *sln, Map* map, bool *val);

    /**
     * @brief Generates a single solution for the map O(N!)
     * @author Ritik Jain
     * @date 29/08/2019
     * @param map  A starting map to progress
     * @return A single solution to the map
     */
    Solution* singleSolution(Map *map);

private:

    /**
     * @author Ritik Jain
     * @date 29/08/2019
     * @param map  The map in which the conflict is to be found
     * @param x  The abscissa of the point where the conflict is to be found
     * @param y  The ordinate of the point where the conflict is to be found
     * @brief Checks if there will be a conflict if a queen is placed at a particular point in the given map
     * @return Returns true if there is a conflict
     */
    bool isConflict(Map *map, unsigned int x, unsigned int y);

    /**
     * @author Ritik Jain
     * @date 29/08/2019
     * @param map  The map of the solution which is to be added to the solution stack
     * @brief Adds the given map to the solution stack if it is a valid solution
     * @return Returns true if the addition of the map as a solution was successful
     */
    bool addSolution(Map *map);

    /**
     * @author Ritik Jain
     * @date 29/08/2019
     * @param map  The initial map for generating the solutions
     * @brief Generates and stores valid solutions to the queens problem given an initial map
     */
    void genSolution(Map *map);

    //The valid solutions to the problem
    Solution **slns = nullptr;

    //The Board-Number : N (Board is NxN)
    unsigned int N;

    //The solution pointer (The number of the solutions)
    unsigned int sp;
};

#endif // QUEENSPROBLEM_H
