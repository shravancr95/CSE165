#include "Animal.h"

class Dog:public Animal{
    
public:
    string name;
    int age;
    Dog(string n, int a){
        cout << "Creating Dog" << endl;
        this->setName(n);
        this->setAge(a);
    }
    
    
    void feed(){
        cout << "A bone, please!" << endl;
    }
    
    ~Dog(){
        cout << "Deleting Dog" << endl;
    }
};


