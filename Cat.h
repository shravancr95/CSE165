#include <iostream>
using namespace std;

class Cat : public Animal{
public:
    string name;
    Cat(){}
    Cat(string name){
        this->name = name;
    }
    
    void print(){
        cout << "hi im a cat"<< endl;
    }
    
    
};
