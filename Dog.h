#include <iostream>
using namespace std;

class Dog : public Animal{
public:
    string name;
    Dog(){}
    Dog(string name){
        this->name = name;
    }
    
    void print(){
        cout << "hi im a dog"<< endl;
    }
    
    
};
