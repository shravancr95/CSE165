#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
using namespace std;

struct LinkedList{
    struct Link{
        Link*next;
        void*value;
    }*head;
    LinkedList(void*dat, Link*n){
        head = new Link();
        head->next = n;
        head->value = dat;
        //cout << "heads value is " << *(double*)head->value << endl;
    }
    
    void add(Link*l, int n){
        Link*current;
        current = l;
        for(int i = 0; i < n; i++){
            Link*temp = new Link();
            temp->value = new double(i);
            temp->next = NULL;
            current->next = temp;
            current = current->next;
        }
    }
    void print(){
        Link*temp = head;
        while(temp != NULL){
            cout << *(double*)temp->value << endl;
            temp = temp->next;
        }
    }
    
    void cleanup(){
        Link*temp;
        while(head != NULL){
            temp = head;
            head = temp->next;
            delete temp;
        }
    }
    
};

#endif