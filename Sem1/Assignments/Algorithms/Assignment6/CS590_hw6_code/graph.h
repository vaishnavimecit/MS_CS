#ifndef __AM_GRAPH_H__
#define __AM_GRAPH_H__

#include <limits.h>
#include "random_generator.h"
  


class graph
{
  protected:
    int**	m_edge;
    int**	rand_edge;
    int		no_vert;


  public:

    graph(int);
    ~graph();

    int get_no_of_vertices()
      { return no_vert; }

    void output();
    void output1();

    void initSingleSource(int*,int);
    void relax(int, int, int,int*);
    void bellmanFord(int);
    
    void floydWarshall();
    void floydWarshall1();

  protected:
    void initialize();
    void permutation(int*, int);
};

#endif
