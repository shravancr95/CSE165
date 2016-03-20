#include <iostream>

using namespace std;

struct structSize
{
    char a;
    
    double b;
    
};

//cout<<sizeof(structSize)<<endl;

struct struct1
{
    char c;
    char d;
    double e;
};

//cout<sizeof(structSize)<<endl;

struct struct2
{
    char f,g,h;
    double i;
};

struct struct3
{
    char j, k, l, m;
    double n;
};

struct struct4
{
    
};

struct struct5
{
    char m;
    int n;
    char o;
};

struct struct6
{
    char p;
    char q;
    int r;
};
int main(){
cout<<sizeof(structSize)<<endl;
cout<<sizeof(struct1)<<endl;
cout<<sizeof(struct2)<<endl;
cout<<sizeof(struct3)<<endl;
cout<<sizeof(struct4)<<endl;
cout<<sizeof(struct5)<<endl;
cout<<sizeof(struct6)<<endl;
}
