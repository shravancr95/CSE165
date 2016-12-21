#include <iostream>

class Animal
{
public:
    void eat() { std::cout << "I'm eating generic food."<< std::endl; }
};

class Cat : public Animal
{
public:
    void eat() { std::cout << "I'm eating a rat." << std::endl; }
};

class Dog : public Cat
{
public:
    void eat() { std::cout << "I'm eating a cat." << std::endl; }
};

int main(){
    Animal*a = new Dog;
    Dog*d = new Dog;
    Cat*c = new Dog;
    a->eat();
    d->eat();
    c->eat();
    
    return 0;
}