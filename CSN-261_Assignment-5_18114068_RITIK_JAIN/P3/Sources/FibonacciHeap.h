/**
 * @file FibonacciHeap.h
 * @date 20/09/2019
 * @author Ritik Jain
 * @brief Implements Fibonacci Heap
 */


#ifndef FIBONACCIHEAP_H

#define FIBONACCIHEAP_H

#include <string.h>
#include <iostream>
#include <unordered_set>
#include <iterator>

using namespace std;

namespace asn5
{
    /**
     * @date 20/09/2019
     * @author Ritik Jain
     * @brief Creates, Stores and Operates on Fibonacci Heap [Generic]
     */
    template <class T>
    class FibonacciHeap
    {

        private :

        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Node/ Tree for the fibonacci heap
         */
        class Node
        {
            public :

            Node(Node *_parent, Node **_child, Node* _left, Node *_right,int _rank, bool _marked, T _key) : parent(_parent) , child(_child) , left(_left), right(_right), rank(_rank), marked(_marked), key(_key)
            {

            }
            
            ~Node()
            {
                delete [] child;
            }

            void addChild(Node* _child)
            {
                if(!_child)
                return;

                _child->parent = this;

                Node **__child = new Node* [rank+1];
                int i;
                for(i=0; i < rank; i++)
                __child[i] = child[i];
                __child[rank] = _child;
                for(i=0; i < rank; i++)
                    child[i] = nullptr;
                delete [] child;
                child = __child;
                rank++;
            }

            void removeChild(Node* _child)
            {
                if(!rank)
                return;

                if(!_child || _child->parent!=this)
                return;

                Node** __child = new Node*[rank-1];
                int i,j=0;
                for(i=0; i < rank; i++)
                {
                    if(child[i] == _child)
                    {
                        child[i] = nullptr;
                        continue;
                    }

                    __child[j++] = child[i];
                    child[i] = nullptr;
                }

                delete[] child;
                child = __child;
                rank--;

            }

            //The parent
            Node *parent;
            //The child
            Node **child;
            //The left
            Node *left;
            //The right
            Node *right;
            //The rank [The number of children]
            int rank;
            //The value
            T key;
            //Marked or not
            bool marked;
        };

        /**
         * @date 21/09/2019
         * @author Ritik Jain
         * @brief Finds a node with the given UID in the parent tree
         * @param uid  The UID of the node
         * @param parent  The parent tree
         * @return Node if it is found
         */
        Node* findInTree(int uid, Node *parent)
        {
            if(!parent)
            return nullptr;

            if(parent->key.uid()==uid)
            return parent;

            int j;
            Node * out = nullptr;

            for(j=0; j < parent->rank; j++)
                if(out = findInTree(uid, parent->child[j]))
                    return out;

            return out;

        }

        /**
         * @date 21/09/2019
         * @author Ritik Jain
         * @brief Cuts a marked node and adds it to the rootlist and does this recursively (until an unmarked parent is encountered) ; updates the minimum
         * @param node  The node to be cut
         */
        void cut_unmark(Node* node)
        {
            if(!node || !node->marked)
            return;
            
            if(node->parent)
            {
                
                Node *parent = node->parent;
                parent->removeChild(node);
                node->parent = nullptr;

                node->marked  = false;
                node->left = min;
                node->right = min->right;
                min->right->left = node;
                min->right = node;
                N++;

                if(min->key.compareTo(node->key)==1)
                    min = node;

                if(parent->marked)
                cut_unmark(parent);
                else
                parent->marked = true;
                
            }
            else
                node->marked=false;
            
        }

        /**
         * @date 21/09/2019
         * @author Ritik Jain
         * @brief Finds a node given the uid in the heap
         * @param uid  The UID of the node to be searched for
         * @return The pointer to the node ; nullptr if not found
         */
        Node* findNode (int uid)
        {
            Node *out = nullptr;

            Node *i = min;
            int j;
            for(j=0; j < N; j++, i = i->right)
                if(out = findInTree(uid, i))
                return out;

            return out;
            

        }

        /**
         * @date 21/09/2019
         * @author Ritik Jain
         * @brief Decreases the given node and does it recursively until an unmarked parent is encountered ; updates the minimum
         * @param node  The node to be decreased
         * @param key  The new decreased key
         * @return True if the key was successfully decreased ; false otherwise
         */
        bool decreaseKey(Node* node, T key)
        {
            if(!node)
            return false;

            if(node->key.compareTo(key)==-1)
            return false;

            node->key = key;
            
            if(node->parent)
            {
                if(node->key.compareTo(node->parent->key)<0)
                {
                    node->marked = true;
                    cut_unmark(node);
                }
            }
            else if(min->key.compareTo(node->key)==1)
                min = node;
            
            return true;
        }

        //The minimum node
        Node *min;

        //The number of trees in the root list
        int N;

        public :

        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Constructs a new Fibonacci Heap
         */
        FibonacciHeap()
        {
            min = nullptr;
            N = 0;
        }

        ~FibonacciHeap()
        {
            int i;
            for(i=0; i < N; i++ , min = min->right)
            delete min;
        }

        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Finds and updates the minimum
         */
        void update_min()
        {
            int i;
            Node* _min = min;
            for(i=0; i<N; i++, _min = _min->right)
            if(_min->key.compareTo(min->key)==-1)
            min = _min;
        }

        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Inserts an element in the heap [ O(1) time complexity]
         * @param key  The element to be inserted
         */
        void insert(T key)
        {
            if(N)
            {
                Node *node  = new Node(nullptr,nullptr,min,min->right,0,false,key);
                min->right->left = node;
                min->right = node;
                N++;
                if(min->key.compareTo(node->key)==1)
                min = node;

            }
            else
            {
                min = new Node(nullptr,nullptr,nullptr,nullptr,0,false,key);
                min->left = min;
                min->right = min;
                N=1;
            }
            
        }

        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Gets the minimum element in the heap
         * @return The minimum element
         */
        T& getMinimum()
        {
            return min->key;
        }
        
        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Gets the minimum node in the heap
         * @return The minimum heap
         */
        Node* getMinimumNode()
        {
            return min;
        }

        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Extracts the minimum [Removes it] ; consolidates the tree and updates the minimum
         * @return The minimum element [former]
         */
        T extractMinimum()
        {
            if(!N)
            {
                const char *exc = "Heap Empty";
                throw exc;    
            }

            T min_key = min->key;
            Node *_min = min;

            N--;

            if(min->rank)
            {
                _min = min->child[0];

                for(int i=0; i < min->rank-1; i++)
                {
                    min->child[i]->right = min->child[i+1];
                    min->child[i+1]->left = min->child[i];
                    min->child[i]->parent = nullptr;
                }
                min->child[min->rank-1]->parent = nullptr;

                if(N)
                {
                    min->child[0]->left = min->left;
                    min->left->right = min->child[0];
                    min->child[min->rank-1]->right = min->right;
                    min->right->left = min->child[min->rank-1];
                }
                else
                {
                    min->child[0]->left = min->child[min->rank-1];
                    min->child[min->rank-1]->right = min->child[0];
                }

                N+=min->rank;
            }
            else if(N)
            {
                _min = min->left;
                min->left->right = min->right;
                min->right->left =  min->left;
            }

            min->child = nullptr;
            delete min;

            min = _min;

            update_min();
            
            consolidate();
            
            return min_key;
            
        }

        /**
         * @date 20/09/2019
         * @author Ritik Jain
         * @brief Consolidates the tree [No two trees in the root list have the same rank] ; updates the minimum
         */
        void consolidate()
        {
            if(N<=1)
                return;
            
            struct H
            {
                public :
                size_t operator () (Node* const &k) const
                {
                    return hash<int>()(k->rank);
                }
            };

            struct C
            {
                public :
                bool operator () (Node* const &k1, Node* const &k2) const
                {
                    return k1->rank==k2->rank;
                }
            };

            unordered_set<Node*,H,C> ranks;
            typename unordered_set<Node*,H,C>::iterator i;

            Node *c = min;

           while ( ((i = ranks.find(c)) == ranks.end()) || ((*i)!=c))
           {
                if(i != ranks.end() && ((*i)->rank==c->rank))
                {
                    Node *x = *i;
                    ranks.erase(x);

                    if(c->key.compareTo(x->key)==1)
                    {
                    
                    if(N==2)
                    {
                        x->left = x;
                        x->right = x;
                    }
                    else
                    {
                        x->left->right = x->right;
                        x->right->left = x->left;
                        x->left = c->left;
                        x->right = c->right;
                        c->left->right = x;
                        c->right->left = x;
                    }
                    c->parent = x;
                    c->left = c->right = nullptr;
                    x->addChild(c);
                    c = x;
                    }
                    else
                    {
                        if(N==2)
                        {
                            c->left = c;
                            c->right = c;
                        }
                        else
                        {
                            x->left->right = x->right;
                            x->right->left = x->left;
                        }
                        x->parent = c;
                        x->left = x->right = nullptr;
                        c->addChild(x);
                    }

                    N--;
                }
                else
                {
                   ranks.insert(c);
                   c = c->right;
                }
                
                min = c;
           }

           update_min();

            
        }

        /**
         * @date 22/09/2019
         * @author Ritik Jain
         * @brief Finds the element with the given uid in the heap
         * @param uid  The uid of the element to be searched
         * @return  The element
         */
        T find (int uid)
        {
            return findNode(uid)->key;
        }

        /**
         * @date 22/09/2019
         * @author Ritik Jain
         * @brief Decreases the element with the given uid
         * @pararm uid  The uid of the element to be decreased
         * @param key  The new decreased key
         * @return True if the key was decreased successfully ; false otherwise
         */
        bool decreaseKey(int uid, T key)
        {
            Node *node = findNode(uid);
            return decreaseKey(node, key);
        }
    };
}

#endif //FIBONACCIHEAP_H