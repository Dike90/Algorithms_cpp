#ifndef __BINSEARCH_H__
#define __BINSEARCH_H__

template <typename Key,typename Value>
class BinSearchST{
public:
    BinSearchST(int capacity) :N(0) { keys = new Key[capacity]; vals = new Value[capacity];};
    int size() { return N;};
    Value get(Key key) {
        if(isEmpty()) return NULL;
        int i = rank(key);
        if( i < N && keys[i] == key) return vals[i];
        else return NULL;
    }; 
    //若key在当前表中则返回key在数组keys中的索引
    //否则返回的是表中小于被查找key的数量
    //而此时，返回的索引指向keys中第一个大于key的元素
    int rank(Key key){
        int lo = 0, hi = N -1;
        while(lo <= hi){
            int mid = (lo + hi) / 2;
            if(key < keys[mid]) hi = mid - 1;
            else if(key > keys[mid]) lo = mid + 1;
            else return mid;
        }
        return lo;
    };
    void put(Key key, Value val){
        int i = rank(key); //key在数组keys中的索引
        //当前添加的元素已经在表中，则更新对应的value
        if( i < N && keys[i] == key) { vals[i] = val; return;}
        //否则将新的key-value对添加进表中
        for(int j = N ; j > i ; j--){
            keys[j] = keys[j-1]; vals[j] = vals[j-1];
        }
        keys[i] = key; vals[i] = val;
        N++;
    };

    bool isEmpty() { return N==0;};

    Key *keys;
    Value *vals;
    int N;

};

#endif