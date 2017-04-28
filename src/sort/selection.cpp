#include <iostream>
#include <stack>
#include <fstream>
#include <cstdlib>
#include <chrono>
void exch(int a[] , int i , int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}
//largeW.txt 100W ints takes 1261.15s
void SelectionSort(int *a, int asize){
    for(int i =0; i< asize ; i++)
    {
        int min = i;
        for(int j = i + 1 ; j < asize ; j++){
            if(a[j] < a[min])
                min = j;
        }
        exch(a, min , i );
    }
}
bool isSorted(int *a , int asize){
    for(int i=1; i< asize ; i ++){
        if(a[i] < a[i-1])
            return false;
    }
    return true;
}
int main(){
    using namespace std;
    using namespace chrono;
    const int dataSize=1000000;
    int* pint_data = new int[dataSize];
    ifstream fin("algs4-data/largeW.txt");
    if(!fin.is_open()){
        cout<<"file open failed!\n";
    }
    else{
        int i=0;
        while(!fin.eof())
        {
            char szchar[10];
            fin.getline(szchar,10);
            pint_data[i++]=atoi(szchar);
        }
        steady_clock::time_point t1 = steady_clock::now();
        SelectionSort(pint_data,dataSize);
        steady_clock::time_point t2 = steady_clock::now();
        if(!isSorted(pint_data,dataSize))                                   
            cout<<"sort erro\n";
        else{
            for(int i =0 ; i< dataSize ; i++){      
                cout<<pint_data[i]<<endl;
            }
        }
        duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
        std::cout << "It took me " << time_span.count() << " seconds.";

    }
    
    
    cin.get();
    return 0;
}