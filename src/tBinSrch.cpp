#include <iostream>
#include "../include/BinSearchST.h"
using namespace std;

int main(){
    BinSearchST<string,string> tbin(8);
    cout<<tbin.size()<<endl;
    for(int i = 0; i< 4 ; i++){
        string key,val;
        cin>>key>>val;
        tbin.put(key,val);
    }
    cout<<"the key-value's size is:"<<tbin.size()<<endl;
    cout<<"find something:"<<endl;
    string findme;
    cin>>findme;
    cin.get();
    cout<<tbin.rank(findme)<<endl;
    cout<<"find"<<findme<<"is:"<<tbin.get(findme)<<endl;

    while(1);

    return 0;
}