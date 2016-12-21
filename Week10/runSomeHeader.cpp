#include <vector>
#include "SomeHeader.h"

int main(){
    vector <A*> v;
    initVec(v);
    
    for(int i = 0; i < v.size(); i++){
        cout << typeid(*v[i]).name() << endl;
    }
}