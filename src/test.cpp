#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> *v;
    v = new vector<int>[10];
    for( int i = 0 ; i<10; i++ )
    {
        for (int j = 0; j <10; j++){
            v[i].push_back(j);
        }
    }
    for(int i = 0; i<10 ; i++)
        for(int j =0; j< 10; j++)
            cout<<v[i][j];
    cin.get();
    return 0;
}