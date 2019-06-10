#include <iostream>
#include "graph.h"
#include "random_generator.h"

using namespace std;

int main(int argc, char* argv[])
{ 
 cout << "Constant Input:" << endl;
 cout << "---------------" << endl;
 graph g(5);
 g.bellmanFord(0);
 g.floydWarshall();
 
 cout << "-----------------------------------------------------------" << endl;
 cout << "Random Input:" << endl;
 cout << "-------------" << endl;
 srand(time(0));
 int no_vert = 5+rand()%6;
 cout << "The no. of vertices are " << no_vert << endl;
 graph g1(no_vert);
 g1.bellmanFord(0);
 g1.floydWarshall1();
  
    return 0;
}