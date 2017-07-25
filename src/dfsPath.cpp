#include <iostream>
#include "../include/dfsPath.h"

using namespace std;

int main(){
    ifstream fin("../algs4-data/tinyCG.txt");
    Graph graph(fin);
    DFSPaths dfspath(graph,0);
    stack<int> path;
    path = dfspath.pathTo(4);
    while(!path.empty()){
        std::cout<<path.top()<<" ";
        path.pop();
    }
        
    cout<<endl;
    

    cin.get();
    return 0;
}