#include <iostream>
#include "graph.h"

using namespace std;

// Creates a graph of size param1
Graph::Graph(int nodes)
{
    this->nodes = nodes; 
    adj = new list<int>[nodes];
}

void Graph::set_edge(int v, int w) 
{ 
    adj[v].push_back(w);
}

// Runs dfs
void Graph::DFSVisit(int v, bool visited[])
{
    visited[v] = true; 
    cout << v << " "; 

    list<int>::iterator i; 
    for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        if(!visited[*i]) 
            DFSVisit(*i, visited); 
}

void Graph::dfs(int v)
{
    bool *visited = new bool[nodes]; 
    for (int i = 0; i < nodes; i++) 
    visited[i] = false; 

    DFSVisit(v, visited);
}

//Run bfs
void Graph::bfs(int s)
{
    bool *visited = new bool[nodes]; 
    for(int i = 0; i < nodes; i++) 
        visited[i] = false; 

    list<int> queue; 
  
    visited[s] = true; 
    queue.push_back(s); 
  
    list<int>::iterator i; 
  
    while(!queue.empty()) 
    { 
        // Dequeue a vertex from queue and print it 
        s = queue.front(); 
        cout << s << " "; 
        queue.pop_front(); 
  
        for (i = adj[s].begin(); i != adj[s].end(); ++i) 
        { 
            if (!visited[*i]) 
            { 
                visited[*i] = true; 
                queue.push_back(*i); 
            } 
        } 
    } 
}