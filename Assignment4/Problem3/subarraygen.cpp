/**
  * @file subarraygen.cpp
  * @author Ritik Jain
  * @date 01/09/2019
  * @brief Finds the longest subarray with a given sum of elements
  */

#include "subarraygen.h"

pair<int,int> gen_n_subarray(int &N, int &n, int* &e)
{

pair<int,int> SLN (0,0);

unordered_set <Key, KeyHash, KeyComp> prefix_sum;

unordered_set <Key, KeyHash, KeyComp> :: iterator hit;
Key search_key(0,0);
int sum=0;
int j;

for(j=0; j<N; j++)
{
sum += e[j];

search_key = Key(j,sum);
hit = prefix_sum.find(search_key);

if(hit!=prefix_sum.end() && (hit->i > j))
hit->i=j;
else
{
prefix_sum.insert(search_key);
}
search_key = Key(0,sum-n);
hit = prefix_sum.find(search_key);
if(hit!=prefix_sum.end() && ((j-hit->i) > (SLN.second-SLN.first)))
{
SLN.first = hit->i+1;
SLN.second = j;
}
else if(sum==n && j>(SLN.second-SLN.first))
{
SLN.first=0;
SLN.second=j;
}
}

return SLN;
}

int main( int argc, char **argv)
{
int N;
int n;
int *e;
int j;
pair<int,int> sln(0,0);
char k='c';

cout << "Sum Subarray Generator ver 1" << endl << endl;
while(k=='c')
{
cout << "Enter :" << endl << "[ N ] : ";
cin >> N;
cout << "[ n ] : ";
cin >> n;
cout << "[ e* ] : ";
e = new int[N];
for(j=0; j < N; j++)
cin >> e[j];
cout << endl << "Solution :" << endl;
sln = gen_n_subarray(N,n,e);
if(sln.first-sln.second)
cout << "The largest subarray of sum " << n << " has a size : " << "[ " << (sln.second-sln.first)+1 << " ]" << endl<<"The subarray ranges from index : [ " << sln.first << " to " << sln.second << " ]" << endl;
else
cout << "No solution found!" << endl;
cout << endl;
cout << "Enter [ c ] to continue ; otherwise to quit : ";
cin >> k;
cout << endl;
}

return 0;
}

