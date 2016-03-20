#include <iostream>
#include "math.h"


using namespace std;

class Circle{
    private:
        double X, Y, R;
   
    public:
    Circle();
    Circle(int a, int b, int c);
    void setX(double k);
    void setY(double k);
    void setR(double k);
    double getX();
    double getY();
    double getR();
    double area;

};

Circle::Circle(){
    X = 0;
    Y = 0;
    R = 1;
    area = M_PI*R*R;
}

Circle::Circle(int a, int b, int c){
    X = a;
    Y = b;
    R = c;
    area = M_PI*R*R;
}

void Circle::setX(double k){
    X = k;
}

void Circle::setY(double k){
    Y = k;
}

void Circle::setR(double k){
    R = k;
    area = M_PI*R*R;
    
}

double Circle::getX(){
    return X;
}

double Circle::getY(){
    return Y;
}

double Circle::getR(){
    return R;
}

