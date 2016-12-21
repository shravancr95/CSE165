#include <iostream>
#include <vector>
using namespace std;

template <class T>
class DynArray{
public:
    vector <T>v;
    void add(T t){
        v.push_back(t);
    }
    
    int size(){
        return v.size();
    }
    
    T operator [](const int i){
        return v[i];
    }
};

