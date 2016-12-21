#include <iostream>
using namespace std;

class Animal{
public:
	string name;
	Animal(){
	}

	Animal(string name){
		this->name = name;
	}
	void print(){
		cout << "hi, im a generic animal"<< endl;
	}

};
