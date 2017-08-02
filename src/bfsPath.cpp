#include <iostream>
#include "../include/bfsPath.h"

using namespace std;

int main(){
    ifstream fin("../algs4-data/tinyCG.txt");
    Graph graph(fin);
    BreadthFirstPaths bfspath(graph,0);
    stack<int> path;
    for (int v =0 ; v < 6 ;v++){
        path = bfspath.pathTo(v);
        cout << "0 to "<<v<<": ";
        while(!path.empty()){
            std::cout<<path.top()<<" ";
            path.pop();
        }
            
        cout<<endl;
    }

    

    cin.get();
    return 0;
}