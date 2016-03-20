#ifndef STACK_H
#define STACK_H

#include <iostream>

struct Stack {
	struct Link {
		void* data;
		Link* next;
		
		void initialize(void* dat, Link* nxt){
			data = dat;
			next = nxt;
		}
	}* head;
	
    
	void initialize(){
		head = 0;
	}
	
	void push(void* dat){
		Link* newLink = new Link;
		newLink->initialize(dat, head);
		head = newLink;
	}
	
	void* peek(){
		if (head == 0){
			std::cout << "Stack is empty";
		}
		return head->data;
	}
	
	void* pop(){
		if(head == 0)
			return 0;
		
		void* result = head->data;
		Link* oldHead = head;
		head = head->next;
		delete oldHead;
		return result;
	}
    
    void (*deletecb)(void*pt);
    
    void setDeleteCallback(void(*delcb)(void*pt)){
        deletecb = delcb;
    }
	
	void cleanup(){
        while(head != NULL){
            Link*del_link = head;//have a temp node that keeps track of the head
            deletecb(del_link->data);
            head = head->next; //move the head down so we have a pointer to the head.
            delete del_link;
        }
	}
};
#endif
