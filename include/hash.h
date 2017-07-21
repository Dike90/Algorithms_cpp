#ifndef __HASH_H__
#define __HASH_H__
unsigned int hash_string(const string &str;int tableSize){
    unsigned int hashVal = 0;
    for(char ch : str)
        hashVal = 31*hashVal + ch;
    return hashVal % tableSize;
}

#endif