#include <iostream>
#include <fstream>
#include <cstdlib>
#include <chrono>
#include "../../include/sort.h"
int main(){
    using namespace std;
    using namespace chrono;
    const int dataSize=1000000;
    int* pint_data = new int[dataSize];
    ifstream fin("../../algs4-data/largeW.txt");
    ofstream fout("temp1.txt");
    if(!fin.is_open()){
        cout<<"file open failed!\n";
    }
    else{
        int j=0;
       steady_clock::time_point t0 =steady_clock::now();
        for(int i = 0; i< dataSize ; i++)
        {
            if(fin.eof())
                break;
            char szchar[10];
            fin.getline(szchar,10);
            pint_data[j++]=atoi(szchar);
        }
       steady_clock::time_point t1 =steady_clock::now();

        MergeBUSort(pint_data,dataSize);

       steady_clock::time_point t2 =steady_clock::now();
        if(!isSorted(pint_data,dataSize))                                   
            cout<<"sort error\n";
        else{
            for(int i =0 ; i< dataSize ; i++){      
                fout<<pint_data[i]<<endl;
            }
            cout<<"sorted\n";
        }
       steady_clock::time_point t3 =steady_clock::now();
        auto  time_span0 = duration_cast<microseconds>(t1 - t0);
        auto   time_span1 = duration_cast<microseconds>(t2 - t1);
        auto   time_span2 = duration_cast<microseconds>(t3 - t2);
        std::cout.precision(10);
        std::cout << "Read file took me " << time_span0.count() /1000000.0<< " seconds.\n";
        std::cout << "Write file took me " << time_span2.count()/1000000.0  << " seconds.\n";
        std::cout << "Sort took me " << time_span1.count() / 1000000.0 << " seconds.\n";

    }
    delete [] pint_data;
    fin.close();
    fout.close();
    cin.get();
    return 0;
}