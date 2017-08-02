#ifndef __BFSPATH_H__
#define __BFSPATH_H__
#include<queue>
#include<stack>
#include"graph.h"
class BreadthFirstPaths {
    bool *marked;
    int  *edgeTo;
    const int s;
    void bfs(Graph &g,int s){
        std::queue<int> myqueue;
        marked[s] = true;
        myqueue.push(s);
        while(!myqueue.empty()){
            int v = myqueue.front();
            myqueue.pop();
            for (int w : g.getAdj(v)){
                if (!marked[w]){
                    edgeTo[w] = v;
                    marked[w] = true;
                    myqueue.push(w);
                }
            }
        }
    }
public:
    BreadthFirstPaths(Graph &g,int s): s(s){
        marked = new bool[g.getV()]();
        edgeTo = new int[g.getV()]();
        bfs(g,s);
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