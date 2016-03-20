#include <iostream>
using namespace std;
struct Entry{
    string fname, lname, email;
    int size;
    
    Entry(/*string f, string l, string e*/){
        //fname = f;
        //lname = l;
        //email = e;
    }
    
    void setName(string k){
        fname = k;
    }
    
    void setLastname(string k){
        lname = k;
    }
    
    void setEmail(string k){
        email = k;
    }
    
    string getName(){
        return fname;
    }
    
    string getLastname(){
        return lname;
    }
    
    string getEmail(){
        return email;
    }
    
    
    void print(){
        cout << "First Name: " << getName() << endl;
        cout << "Last Name: " << getLastname() << endl;
        cout << "Email: " << getEmail() << endl;
    }




};
