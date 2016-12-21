/*#include <iostream>

using namespace std;

class Counter {
    
public:
    int ID;
    static int count;
    
    Counter() : ID(count++)
    {
        cout<< ID << " created" << endl ;
    }
    
    
    void * operator new(size_t size)
    {
        cout << "new called" << endl;
        cout << "new" << endl;
        return malloc(size);
    }
    
    
    void operator delete(void * pointer) {
        cout << "delete" << endl;
        free(pointer);
    }
    
    ~Counter() {
          cout << ID << " destroyed" << endl;
    }
    
    void * operator new[] (size_t st)
    {
        cout<< "new " <<st/sizeof(Counter)- 1 << " counters starting at " << count << endl;
        return malloc(st);
        }
        
        void operator delete[] (void * pointer)
        {
            cout<< "delete counters" << endl;
            free(pointer);
        }
        
};*/

#ifndef Counter_h
#define Counter_h
//#include <cstdlib>
using namespace std;

class Counter{
public:
    
    static int count;
    int ID;
    Counter();
    ~Counter();
};

Counter::Counter() : ID(count++){
    //ID = count++;
    cout << "constructor called" << endl;
    cout << ID << " created" << endl;
    
}

Counter::~Counter(){
    cout << "destructor called" << endl;
    cout << ID << " destroyed" << endl;
    
}

void* operator new(size_t sz) {
    cout << "new operator called" << endl;
    cout << "new" << endl;
    //cout << sz << endl;
    return malloc(sz);
}
void operator delete(void* d) {
    cout << "delete operator called" << endl;
    cout << "delete" << endl;
    //	:: operator delete(d);
    free(d);
}

#endif

