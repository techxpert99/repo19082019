/**
  * @file subarraygen.h
  * @author Ritik Jain
  * @date 01/09/2019
  * @brief Sub Array Generator Headers File
  */

#ifndef SUBARRAGEN_H
#define SUBARRAYGEN_H

#include <iostream>
#include <utility>
#include <bits/stdc++.h>

using namespace std;

/**
 * @brief Finds the longest sub array with the sum of elements : n
 * @author Ritik Jain
 * @date 01/09/2019
 * @param N  The length of the array
 * @param n  The parameter [n]
 * @param e  The array of elements
 * @return Returns a pair <i,j> : Where i and j are the starting and the ending indices of the subarray ; Returns <-1,-1> if not found
 */
pair <int,int> gen_n_subarray(int &N, int &n, int* &e);

/**
 * @brief The Key which stores prefix sum and its index value
 * @author Ritik Jain
 * @date 01/09/2019
 */
struct Key
{
public :
//The prefix sum
int psum;
//The index
mutable int i;

Key(int _i, int _psum) : i(_i), psum(_psum)
{
}
};

/**
 * @brief The Comparator for the Hash Function
 * @author Ritik Jain
 * @date 01/09/2019
 */
struct KeyComp
{
public :
bool operator()(const Key &k1, const Key &k2) const
{
return k1.psum==k2.psum;
}
};

/**
 * @brief The Hasher
 * @date 01/09/2019
 * @author Ritik Jain
 */
struct KeyHash
{
public :
size_t operator()(const Key &key) const
{
return hash<int>()(key.psum);
}
};

/**
 * @brief The main function
 * @author Ritik Jain
 * @date 01/09/2019
 */
int main( int argc, char **argv);

#endif //SUBARRAYGEN_H
