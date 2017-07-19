#ifndef __GRAPH_H__
#define __GRAPH_H__
#include<vector>
#include<iostream>
class Graph {
public:
    Graph(int vertex) : V(vertex) , E(0) {
        adj = new std::vector<int>[vertex];
    }
    Graph(std::istream &in){
        int vertex ;
        in>>vertex;
        adj = new std::vector<int>[vertex];
        int E;
        in>>E;
        int v,w;
        for (int i =0; i < E; i++){
            in>>v;
            in>>w;
            addEdge(v,w); 
        }
    }
    void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
        ++E;
    }
    int getV() {return V;}
    int getE() {return E;}
private:
    int V; //vertex 顶点个数
    int E; //edge 边数
    std::vector<int> *adj;  // 邻接表
};

#endif