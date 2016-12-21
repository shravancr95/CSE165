//#include "Vec.h"
#include <vector>
using namespace std;

class Vec {
    
public:
    static Vec null;
    float x, y;
    Vec(){
        x = 0;
        y = 0;
    }
    
    Vec(float a, float b){
        x = a;
        y = b;
    }
    
    float get_x(){
        return x;
    }
    
    float get_y(){
        return y;
    }
    
    void add(Vec&a){
        this->x += a.x;
        this->y += a.y;
    }
    
    void print(){
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }
};


class XYData{
public:
    vector <Vec*> v;
    
    XYData(){
    }
    
    void add(Vec*a){
        v.push_back(a);
    }
    
    virtual void generate(float xinit, float xend, float inc){
    }
    
    Vec&max(){
        int x_max = INT_MIN;
        int y_max = INT_MIN;
        //cout << "max val of y = " <<  y_max << endl;
        //pointer to make changes in memory
        Vec*result = new Vec();
        //cout << "the result initially is " << result->x << " " << result->y << endl;
        for(int i = 0; i < v.size(); i++){
            if(y_max < v[i]->get_y()){
                //point to memory address
                y_max = v[i]->get_y();
                result = v[i];
                //cout << "result = " << v[i].x << " " << v[i].y << endl;
                //cout << "result now equals " << v[i]->get_x <<
            }
            
        }
        //cout << result->get_x() << " *in max()* " << result->get_y() << endl;
        //return in value
        return*result;
    }
    
    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i]->get_x() << " " << v[i]->get_y() << endl;
        }
    }
    
};

class QuadraticCurve : public XYData{
public:
    float a, b, c;
    QuadraticCurve(){
        a = b = c = 0;
    }
    
    QuadraticCurve(float a, float b, float c){
        this->a = a;
        this->b = b;
        this->c = c;
    }
    
    virtual void generate(float xinit, float xend, float inc){
        float y = 0;
        for(int x = xinit; x <= xend; x+= inc){
            y = a*x*x + b*x + c;
            this->add(new Vec(x, y));
        }
    }
    
    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i]->get_x() << " " << v[i]->get_y() << endl;
        }
    }

    
    
};

class CubicCurve : public XYData{
public:
    float a, b, c, d;
    CubicCurve(){
        a = b = c = d = 0;
    }
    
    CubicCurve(float a, float b, float c, float d){
        this->a = a;
        this->b = b;
        this->c = c;
        this->d = d;
    }
    
    virtual void generate(float xinit, float xend, float inc){
        float y = 0;
        for(int x = xinit; x <= xend; x+= inc){
            y = a*x*x*x + b*x*x + c*x + d;
            this->add(new Vec(x, y));
        }
    }
    
    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i]->get_x() << " " << v[i]->get_y() << endl;
        }
    }
    
};


