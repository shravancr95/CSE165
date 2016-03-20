#include <iostream>
#include "Vec.h"
using namespace std;

class Rect{
    
public:
    Vec A,B,C,D;
    float height, width;
    Rect();
    Rect(double a, double b, double w, double h){
        //(a,b) is upper left hand
        //c is width
        //d is height
        A.x = a;
        A.y = b;
        //B(a+w,b);
        B.x = a+w;
        B.y = b;
        //C(a,b-h);
        C.x = a;
        C.y = b-h;
        //D(a+w, b-h);
        D.x = a+w;
        D.y = b-h;
    }
    
    bool contains(Vec b){
        if((b.x >= this->A.x && b.x <= this->B.x)&&(b.y <= this->A.y && b.y >= this->C.y)){
            return true;
        }
        return false;
    }
    
    void print(){
        cout << "Rectangle contains coordinates as follows" << endl;
        cout << "(" << A.x << "," << A.y << ")" << endl;
        cout << "(" << B.x << "," << B.y << ")" << endl;
        cout << "(" << C.x << "," << C.y << ")" << endl;
        cout << "(" << D.x << "," << D.y << ")" << endl;
    }
};