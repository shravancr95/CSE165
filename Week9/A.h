#ifndef LA7_A_h
#define LA7_A_h

#include <iostream>

using namespace std;

class A {
    int i;
    int f;
public:
    A(){
        cout << "Creating object" << endl;
        doSomething();
    }
    
    void start(){
        i = 1;
        f = 1;
        
    }
    
    virtual void doSomething(){
        cout << "B::doSomething()" << endl;
    }
};

#endif