#ifndef __HEAPSORT_H__
#define __HEAPSORT_H__
//largeW.txt 100W ints takes about 0.4s on i3-4150 ,win7 64 bits
template<typename T>
class HeapSort{
public:
    HeapSort(T*a , int len):a(a),len(len) {};
    void sort(){
        int N = len;
        for(int i=len/2; i >=1; i--)
            sink(i,N);
        while(N>1){
            exch(1,N--);
            sink(1,N);
        }
    };
private:
    T* a;
    int len;
    void exch(int i , int j){
        T t = a[i]; a[i] = a[j]; a[j] = t;
    };
    void sink(int r , int N){
        while(2*r<=N){
            int k = 2*r;
            if(k<N && a[k] <= a[k+1])  k++;
            if(a[r] >= a[k]) break;
            exch(r, k);
            r=k;
        }
    };
};

#endif