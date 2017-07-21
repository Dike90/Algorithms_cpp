#include <iostream>
#include <string>
#include "../include/BST.h"
using namespace std;

int main(){
    BST<int,string> testBST;
    testBST.insert(14,"230");
    testBST.insert(9,"1234");
    testBST.insert(56,"2341");
    testBST.insert(8,"asdf");
    testBST.insert(11,"sdfe");
    testBST.insert(12,"dsfaa");
    testBST.insert(55,"saf");
    testBST.insert(24,"asdf");

    cout<<testBST.get(8)<<endl;
    cout<<"the tree's size is: "<<testBST.size()<<endl;
    cout<<"the minimum key in the tree is: "<<testBST.min()<<endl;
    cout<<testBST.floor(88)<<endl;
    cout<<testBST.select(4)<<endl;
    testBST.printTree();
    testBST.delKey(11);
    cout<<"after delKey"<<endl;
    testBST.printTree();
    while(1);
    return 0;
}