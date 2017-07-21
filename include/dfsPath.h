#ifndef __DFSPATH_H__
#define __DFSPATH_H__
#include "../include/graph.h"
class DFSPaths{
    bool marked;
    int *edgeTo;
    const int s;
public:
    DFSPaths(Graph &g,int s){
        marked = new bool[g.getV()];
        edgeTo = new int[g.getV()];
        
    }
};

#endif