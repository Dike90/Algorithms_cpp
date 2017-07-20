#include <iostream>
#include <fstream>
#include "../include/graph.h"
using namespace std;
int main(){
    ifstream fin("../algs4-data/tinyCG.txt");
    Graph tgraph(fin);
    tgraph.printGraph(cout);

    cin.get();
    return 0;
}