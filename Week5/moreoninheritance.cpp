#include <string>
#include "Animal.h"
#include "Dog.h"
#include "display.h"
using namespace std;

int main(){
    
    int n;
    cin>>n;
    char type;
    int age;
    string name;
    
    vector<Animal*> v;
    
    //Animal*a;
    //Dog*d;
    
    for(int i = 0; i < n; i++){
        cin>>type;
        cin>>name;
        cin>>age;
        if(type == 'A'){
            Animal*a = new Animal();
            a->setName(name);
            a->setAge(age);
            v.push_back(a);
        }
        if(type == 'D'){
            Dog*d = new Dog(name, age);
            v.push_back(d);
        }
        
        
        //display(v);
    }
    
    display(v);
}
