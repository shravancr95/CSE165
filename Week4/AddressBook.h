#include "Entry.h"
#include <iostream>
#include <vector>

struct AddEntry{
    string fname, lname, email;
    void print(){
        
    }
};

int counter = 1;

struct AddressBook{
    
    AddEntry*ent;
    AddressBook*next;
    
    AddressBook(string f, string l, string e){
        ent = new AddEntry();
        ent->fname = f;
        ent->lname = l;
        ent->email = e;
        //v.push_back(this);
        next = NULL;
        //prev = NULL;
    }
    
    void add(AddressBook*n){
        AddressBook*temp = this;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = n;
        
        counter++;
    }
    
    void print(){
        AddressBook*temp = this;
        
        while(temp!=NULL){
            cout << "First Name: " << temp->ent->fname << endl;
            cout << "Last Name: " << temp->ent->lname << endl;
            cout << "Email: " << temp->ent->email << endl;
            cout << endl;
            temp = temp->next;
        }
    }
};

//vector<AddressBook> v;
