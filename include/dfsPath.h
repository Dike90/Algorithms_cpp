#ifndef __DFSPATH_H__
#define __DFSPATH_H__
#include <stack>
#include "../include/graph.h"
class DFSPaths{
    bool *marked;
    int *edgeTo;
    const int s;
    void dfs(Graph &g,int v){
        marked[v] = true;
        for (int w : g.getAdj(v))
            if ( !marked[w]){
                edgeTo[w] = v;
                dfs(g,w);
            }
    }
public:
    DFSPaths(Graph &g,int s) : s(s){
        marked = new bool[g.getV()]();
        edgeTo = new int[g.getV()]();
        dfs(g,s);
    }
    ~DFSPaths(){
        delete [] marked;
        delete [] edgeTo;
    }
    bool hasPathTo(int v){
        return marked[v];
    }
    std::stack<int> pathTo(int v){
        std::stack<int> path;
        if (!marked[v]) return path;
        for (int x=v; x != s; x = edgeTo[x])
            path.push(x);
        path.push(s);
        return path;
    }
};

#endif