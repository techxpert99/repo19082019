/**
 * @file MinimumSpanningTreeKruskalUnionFindGenerator.h
 * @date 18/09/2019
 * @author Ritik Jain
 * @brief Minimum Spanning Tree Generation Declarations File
 */

#ifndef MINIMUMSPANNINGTREEGENERATOR_H

#define MINIMUMSPANNINGTREEGENERATOR_H

#include <tuple>
#include <iostream>
#include <string.h>
#include <fstream>

using namespace std;

namespace asn5
{
    /**
     * @date 18/09/2019
     * @author Ritik Jain
     * @brief Contains methods for Generating MST
     */
    class MSTGen
    {
        public:

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Constructor
         */
        MSTGen();

        ~MSTGen();

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Generates the Minimum Spanning Tree from the given graph using Kruskal's Algorithm with Union-Find
         */
        void  genMST();

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
         * @brief Displays the graph/ MST
         */
        void display();

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Tells the weights of the MST / Graph
         * @return Returns the weight
         */
        int weight();

        private:

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Sorts the edges according to their weights in ascending order
         */
        void weightedSort();


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
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Detects whether the given graph/ tree/ forest has a cycle or not [ using Union-Find algorithm ]
         * @param NE  The number of edges in the graph/ tree/ forest
         * @param E  The graph/ tree/ forest
         * @return Returns true if a cycle was found ; false otherwise
         */
        bool hasCycle(int NE, tuple<int,int,int>* &E);

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Finds the set to which a vertex belongs to
         * @param v  The vertex
         * @param parent  The forest (parent) which holds the vertices
         * @return Returns the subset to which the vertex belongs. Returns -1 if its not found in any subset
         */
        int find(int v, int *parent);

        /**
         * @date 18/09/2019
         * @author Ritik Jain
         * @brief Union-Find Algorithm
         * @param v1  The first vertex
         * @param v2  The second vertex
         * @param parent  The forest (parent)
         * @return Returns true if the union was successful ; Returns false otherwise [ meaning a cycle was found ]
         */
        bool union_find(int v1, int v2, int *parent);

        void trim(char* &s);

        bool isValid();

        int addVertex(char *v);

        //The graph/ mst/ forest
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

#endif //MINIMUMSPANNINGTREEGENERATOR_H