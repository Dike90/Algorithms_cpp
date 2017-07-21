#ifndef __MAXPQ_H__
#define __MAXPQ_H__
//对于一个含有N个元素的基于堆的优先队列，插入元素的操作只需要不超过lgN+1次的比较
//删除最大的元素的操作需要不超过2lgN次比较
template <typename Key>
class MaxPQ {
public:
    MaxPQ() ;
    MaxPQ( int max)  { pq = new Key[max + 1];};
    MaxPQ( Key *v) {};
    ~MaxPQ() { delete [] pq;};
    void insert(Key v) {pq[++N] = v; swim(N);};
    Key max();
    Key delMax() {
        Key max = pq[1];
        exch(1 , N--);
        pq[N+1] = 0;
        sink(1);
        return max;
    };
    bool isEmpty() {return N==0;};
    int size() { return N;};
private:
    bool exch(int i , int j) { Key t = pq[i]; pq[i] = pq[j]; pq[j] = t;};
    void swim(int k ) {
        while(k >1 &&pq[k] > pq[k/2]){
            exch( k , k/2);
            k = k / 2;
        }
    };
    void sink(int k) {
        while( 2* k <= N){
            int j = 2*k;
            if(j <N && pq[j] < pq[j+1]) j++;
            if(pq[k] >= pq[j]) break;
            exch( k , j );
            k = j;
        }
    };
    int N = 0;
    Key *pq;
};


#endif