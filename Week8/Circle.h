#include "Sortable.h"

class Circle : public Sortable{
public:
    double r;
    //double pi = 3.14159;
    Circle(){
        r = 0;
    }
    
    Circle(double radius){
        r = radius;
    }
    
    virtual bool compare(const Sortable*s){
        //cout << "calling circle.h " << endl;
        //const Circle*c = s;
        return this->compareCircles((Circle*)(s));
    }
    
    bool compareCircles(const Circle*s){
        if(this->r < s->r){
            return true;
        }
        return false;
    }

    
    virtual void print(){
        cout << "Circle with radius: " << r << endl;
    }
    
};
