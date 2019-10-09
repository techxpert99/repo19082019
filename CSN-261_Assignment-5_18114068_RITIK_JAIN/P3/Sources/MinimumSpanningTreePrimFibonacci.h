/**
 * @file MinimumSpanningTreePrimFibonacci.h
 * @date 19/09/2019
 * @author Ritik Jain
 * @brief Minimum Spanning Tree Generator using Prim's Algorithm with Fibonacci Data Structure
 */

#ifndef MINIMUMSPANNINGTREEPRIMFIBONACCI_H

#define MINIMUMSPANNINGTREEPRIMFIBONACCI_H

#include <iostream>
#include <tuple>
#include <string.h>
#include "FibonacciHeap.h"
#include <fstream>

using namespace std;

namespace asn5
{
    /**
     * @date 19/09/2019
     * @author Ritik Jain
     * @brief Generates MST from a Graph
     */
    class MSTGen
    {
        public:

        /**
         * @date 19/09/2019
         * @author Ritik Jain
         * @brief Constructor
         */
        MSTGen();

        /**
         * @date 19/09/2019
         * @author Ritik Jain
         */
        void genMST();

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Loads the graph from its csv file
         * @param file_name  The path of the csv file
         * @return Returns true if the load was successfull ; false otherwise
         */
        bool load_csv(const char *file_name);

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Saves the graph to its dot file
         * @param file_name  The path of the dot file
         * @return Returns true if the save was successful ; false otherwise
         */
        bool save_dot(const char *file_name);

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Displays the graph
         */
        void displayGraph();

        /**
         * @date 22/09/2019
         * @author Ritik Jain
         * @brief Displays the graph
         */
        void displayMST();

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Tells the weights of the Graph
         * @return Returns the weight of the graph
         */
        int weightGraph();

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Tells the weights of the MST
         * @return Returns the weight of the mst
         */
        int weightMST();        

        private:

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Pushes an edge into a graph/ tree/ forest
         * @param N  The number of edges present in the graph/ tree/ forest [updated automatically]
         * @param T  The graph/ tree/ forest [updated automatically]
         * @param E  The edge to be pushed
         */
        void pushTuple(int &N, tuple<int,int,int>* &T, tuple<int,int,int> &E);

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Pops an edge out of a graph/ tree/ forest
         * @param N  The number of edges present in the graph/ tree/ forest [updated automatically]
         * @param T  The graph/ tree/ forest [updated automatically]
         */
        void popTuple(int &N, tuple<int,int,int>* &T);

        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Calculates the adjascent vertices and updates their keys
         */
        void cut(int v);

        void trim(char* &s);

        bool isValid();

        int addVertex(char *v);
        
        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Stores <Vertex, Key> pair along with Comparator Functions
         */
        struct Data
        {
        public :
        Data(int _v, int _key) : v(_v), key(_key)
        {

        }

        int compareTo(const Data &k)
        {
            if(key<k.key)
            return -1;
            else if(key==k.key)
            return 0;
            else
            return 1;
        }

        int uid()
        {
            return v;
        }

        int v;
        int key;
        };

        //The Fibonacci Heap
        FibonacciHeap<Data> heap;

        //The MST
        int *parent;

        //The graph
        tuple<int,int,int> *E;

        //The names of the vertices
        char **V;

        //Number of edges
        int NE;
        
        //Number of vertices
        int NV;
        
        //Buffer Size
        static const int BUFSZ = 1024;
        
        //Buffer
        char BUF[BUFSZ];
    };
}

#endif //MINIMUMSPANNINGTREEPRIMFIBONACCI_H