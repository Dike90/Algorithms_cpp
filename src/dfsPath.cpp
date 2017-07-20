#include <iostream>
#include "../include/graph.h"

using namespace std;

int main(){
    ifstream fin("../algs4-data/tinyCG.txt");
    Graph graph(fin);
    bool *marked = new bool[graph.getV()];
    int *edgeTo = new int[graph.getV()];
    

    cin.get();
    return 0;
}