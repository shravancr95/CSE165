#include <iostream>
#include <math.h>

#include "DynArray.h"

using namespace std;

template <class A>
class Iterator
{ int cur;
    A& arr;
public:
    Iterator ( A& a ): cur(0), arr(a) {}
    void begin () { cur = 0; }
    void end () { cur = arr.size()-1; }
    bool atend () { return cur==arr.size()-1; }
    void advance () { if ( cur<arr.size()-1 ) cur++; }
    void print () { cout<<cur<<" : "<<arr[cur]<<endl; }
};

template <class A, class X>
void add_five ( A& a )
{
    for ( int i=0; i<5; i++ )
        a.add ( (X)( 2.0*sin(double(i)) ) );
};


int main(int argc, const char * argv[])
{
    DynArray<int> ia;
    add_five<DynArray<int>,int> ( ia );
    
    DynArray<float> fa;
    add_five<DynArray<float>,float> ( fa );
    
    { Iterator<DynArray<int> > it(ia);
        for ( it.begin(); !it.atend(); it.advance() ) it.print();
    }
    
    { Iterator<DynArray<float> > it(fa);
        for ( it.begin(); !it.atend(); it.advance() ) it.print();
    }
    
    return 0;
}

