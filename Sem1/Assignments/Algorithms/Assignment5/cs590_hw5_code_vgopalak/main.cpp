#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

int main()
{
    cout << "Hello" << endl;

    Graph g(5);
    g.set_edge(0, 1); 
    g.set_edge(0, 2); 
    g.set_edge(1, 2); 
    g.set_edge(2, 0); 
    g.set_edge(2, 3); 
    g.set_edge(3, 3);

    cout<< "FOllowing is the DFS:" << endl;
    g.dfs(2);

    cout << "Following is Breadth First Traversal " << endl; 
    g.bfs(2);

    return 0;
}
