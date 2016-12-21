#include "Shared.h"
#include <iostream>
#include <string>

using namespace std;

class Obj: public Shared
{
public:
    string n;
    Obj(string myname)
    {
        cout << "New " <<myname << endl;
        n = myname;
    }
    
    ~Obj()
    {
        cout << "Delete " << n << endl;
    }
};
