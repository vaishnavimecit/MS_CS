#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <iostream>
#include <list>
#include <set>

using namespace std;

class Graph
{
    private:
        // Total number of nodes
        int nodes;
        list<int> *adj; 
        // [nodes x nodes] adjacency matrix
        int **matrix;
        // Helper funciton for dfs, takes a start node and a set of visited nodes as args
        void dfs(int, set<int>*);
        // Helper funciton for bfs, takes a start node and a set of visited nodes as args
        void bfs(int, set<int>*);
    public:
        // Creates a graph of size param1
        Graph(int);

        // Sets the value of the edge (param1, param2) to param3
        void set_edge(int, int);

        // Runs dfs
        void dfs(int);
        void DFSVisit(int, bool*);

        // Runs a bfs from the starting vertex
        void bfs(int);
};

#endif
