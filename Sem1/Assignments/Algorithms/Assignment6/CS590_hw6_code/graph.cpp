
#include "graph.h"
#include <list>
#include <iostream>


using namespace std;


/*
 * constructor/destructor
 */
graph::graph(int n)
{ /*<<<*/
  no_vert = (n > 0) ? n : 1;

/*
 * allocate adjacency matrix
 */
  m_edge = new int*[no_vert];
  for (int i = 0; i < no_vert; i++)
    m_edge[i] = new int[no_vert];

  rand_edge = new int*[no_vert];
  for (int i = 0; i < no_vert; i++)
    rand_edge[i] = new int[no_vert];

  initialize();
} /*>>>*/

graph::~graph()
{ /*<<<*/ 
/*
 * delete nil element and all other allocated nodes
 */
  for (int i = 0; i < no_vert; i++)
    delete[] m_edge[i];
  delete[] m_edge;

  for (int i = 0; i < no_vert; i++)
    delete[] rand_edge[i];
  delete[] rand_edge;
} /*>>>*/


void graph::initialize()
{ /*<<<*/
/*
 * initialize adjacency matrix
 * -> use infinity to allow 0 weight edges
 */
  for (int i = 0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
      m_edge[i][j] = INT_MAX;

      m_edge[0][1]=-1;
      m_edge[0][2]=5;

      m_edge[0][0]=0;
      m_edge[1][1]=0;
      m_edge[2][2]=0;
      m_edge[3][3]=0;
      m_edge[4][4]=0;

      m_edge[1][2]=5;
      m_edge[1][3]=-1;
      m_edge[1][4]=3;

      m_edge[3][1]=-1;
      m_edge[3][2]=5;
      m_edge[4][3]=-3;

  for (int i = 0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
      rand_edge[i][j] = INT_MAX;
  
  srand(time(0));
  for (int i = 0; i < no_vert; i++)
    for (int j = 0; j < no_vert; j++)
      {
        rand_edge[i][j] = (rand()%20-5);
        //cout << rand_edge[i][j] << endl;
      }

} /*>>>*/

void graph::permutation(int* perm, int n)
{ /*<<<*/
  random_generator rg;
  int p_tmp, p_pos;

  for (int i = 0; i < n; i++)
    perm[i] = i;
  
  for (int i = 0; i < n; i++)
    {
      rg >> p_pos;
      p_pos = (p_pos % (n - i)) + i;

      p_tmp = perm[i];
      perm[i] = perm[p_pos];
      perm[p_pos] = p_tmp;
    }
} /*>>>*/

void graph::output()
{ /*<<<*/
  //cout << "[";
  for (int i = 0; i < no_vert; i++)
    {
      cout << "[\t";
      for (int j = 0; j < no_vert; j++)
	if (m_edge[i][j] == INT_MAX)
	  cout << "Inf\t";
	else
	  cout << m_edge[i][j] << "\t";
      cout << "]" << endl;
    }
  //cout << "]" << endl;
} /*>>>*/

void graph::output1()
{ /*<<<*/
  //cout << "[";
  for (int i = 0; i < no_vert; i++)
    {
      cout << "[\t";
      for (int j = 0; j < no_vert; j++)
	if (rand_edge[i][j] == INT_MAX)
	  cout << "Inf\t";
	else
	  cout << rand_edge[i][j] << "\t";
      cout << "]" << endl;
    }
  //cout << "]" << endl;
} /*>>>*/


void graph::initSingleSource(int* weightage, int src)
{
  
  for (int i = 0; i < no_vert; i++) 
      weightage[i]   = INT_MAX; 
    weightage[src] = 0;
}

void graph::relax(int u, int v, int weight, int* dist)
{
         { 
            if (dist[u] + weight < dist[v] && dist[u] != INT_MAX && weight!=INT_MAX) 
                dist[v] = dist[u] + weight;
        }
    
}

void graph::bellmanFord(int src)
{ 
  int* weightage;
  weightage = new int[no_vert];
    initSingleSource(weightage, src);
  if(no_vert==5)
  {
    for (int i = 0; i < no_vert; i++) 
    { 
        for (int j = 0; j <no_vert ; j++) 
        { 
            int u = i;
            int v = j;
            int weight = m_edge[i][j];
            relax(u,v,weight,weightage);
        } 
    } 
    
    cout << "(1)Bellman Ford's Shortest path" << endl;
    cout << "-------------------------------" << endl;
    cout << "Vertex   |Shortest Distance" << endl; 
    
    for (int i = 0; i < no_vert; ++i) 
        cout << i << "        |" << weightage[i] << endl; 
  }
  else
  {  
//Output 2
    if(no_vert!=5)
    {
      for (int i = 0; i < no_vert; i++) 
      { 
          for (int j = 0; j <no_vert ; j++) 
          { 
              int u = i;
              int v = j;
              int weight1 = rand_edge[i][j];
              relax(u,v,weight1,weightage);
          } 
      } 
      
      cout << "(2)Bellman Ford's Shortest path" << endl;
      cout << "Vertex   |Shortest Distance" << endl; 
      
      for (int i = 0; i < no_vert; ++i) 
          cout << i << "        |" << weightage[i] << endl; 
    }
  }
}


void graph::floydWarshall() 
{ 
    int Vx = no_vert;
    int dist[Vx][Vx], i, j, k; 

    for (i = 0; i < Vx; i++) 
        for (j = 0; j < Vx; j++) 
            dist[i][j] = m_edge[i][j]; 
  
    for (k = 0; k < Vx; k++) 
    { 
        for (i = 0; i < Vx; i++) 
        { 
            for (j = 0; j < Vx; j++) 
            {  
                if (dist[i][k] + dist[k][j] < dist[i][j] && m_edge[i][k] != INT_MAX && m_edge[k][j]!=INT_MAX) 
                    dist[i][j] = dist[i][k] + dist[k][j]; 
            } 
        } 
    } 

  cout << "(1)Floyd Warshall's Shortest path" << endl;
  cout << "---------------------------------" << endl;
  output();
}

void graph::floydWarshall1() 
{ 
    int Vx = no_vert;
    int dist[Vx][Vx], i, j, k; 
      
      for (i = 0; i < Vx; i++) 
            for (j = 0; j < Vx; j++) 
                dist[i][j] = rand_edge[i][j]; 
      
        for (k = 0; k < Vx; k++) 
        { 
            for (i = 0; i < Vx; i++) 
            { 
                for (j = 0; j < Vx; j++) 
                {  
                    if (dist[i][k] + dist[k][j] < dist[i][j] && rand_edge[i][k] != INT_MAX && rand_edge[k][j]!=INT_MAX) 
                        dist[i][j] = dist[i][k] + dist[k][j]; 
                } 
            } 
        }
      cout << "(2)Floyd Warshall's Shortest path" << endl;
      cout << "---------------------------------" << endl;
      output1();
}