#include <iostream>
using namespace std;

struct X{
    void*data;
    float m;
    double d;
};


int main(){
    char*f;
    X*s = new X();
    s->data = new int(8);
    s->m = 3.4;
    s->d = 3.4;
    cout << sizeof(f) << endl;
    
	return 0;

}
