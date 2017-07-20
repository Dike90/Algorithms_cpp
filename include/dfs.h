#include "graph.h"

int N = 1024; //N表示图的顶点个数
bool *marked = new bool[N]; 

void dfs(Graph &G, int v){
    marked[v] = true;
    for (int w : G.getAdj(v)){
        if (!marked[w])
            dfs(G,w);
    }
}