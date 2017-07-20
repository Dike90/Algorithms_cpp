#ifndef __GRAPH_H__
#define __GRAPH_H__
#include<vector>
#include<iostream>
#include<fstream>
class Graph {
public:
    Graph(int vertex) : V(vertex) , E(0) {
        adj = new std::vector<int>[vertex];
    }
    Graph(std::istream &in){
        int vertex ;
        in>>vertex;
        V = vertex;
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
        Graph(std::ifstream &in){
        int vertex ;
        in>>vertex;
        V = vertex;
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
    ~Graph(){
        delete [] adj;
    }
    void addEdge(int v, int w){
        adj[v].push_back(w);
        adj[w].push_back(v);
        ++E;
    }
    std::vector<int>& getAdj(int v){
        return adj[v];
    }
    int getV() {return V;}
    int getE() {return E;}
    std::ostream &printGraph(std::ostream &out){
        for (int i = 0 ; i< V; i++){
            out <<i<<": ";
            for (int w : adj[i])
                out << w <<" ";
            out << std::endl;
        }
        return out;
    }
private:
    int V; //vertex 顶点个数
    int E; //edge 边数
    std::vector<int> *adj;  // 邻接表
};

#endif