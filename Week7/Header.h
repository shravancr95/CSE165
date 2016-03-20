#include <iostream>
using namespace std;

class AppRect{
public:
    int x, y;
    int h, w;
    AppRect(){
        x=y=h=w=0;
    }
    AppRect(int x, int y, int width, int height){
        this->x = x;
        this->y = y;
        h = height;
        w = width;
    }
    void setWidth (int a){
        this->w = a;
    }
    void setHeight (int a){
        this->h = a;
    }
};


class AppWindow{
public:
    AppRect*a_rect;
    //int x, y, w, h;
    AppWindow(){
        //this->x=this->y=w=h=0;
    }
    AppWindow(int a, int b, int width, int height){
        a_rect = AppRect(a,b,width,height);
    }
    AppWindow(const AppRect&r){
        a_rect = r;
    }
    AppRect& rect(){
        return a_rect;
    }
    virtual void resize ( int w, int h ){
        //cout << "resize of appwindow" << endl;
        a_rect.setWidth(w);
        a_rect.setWidth(h);
    }
};

class CircleWin: public AppWindow{
public:
    int radius;
    CircleWin() : AppWindow(){
        this->x=this->y=w=h=0;
    }
    
    CircleWin(int a, int b, int w, int h) : AppWindow(a,b,w,h){
        
    }
    
    CircleWin(AppRect&r) : AppWindow(r){
        
    }
    
    void resize(int w, int h){
        this->w = w;
        this->h = h;
        if(w>h){
            radius = h;
            cout << "radius: " << h << endl;
        }
        else if (h>w){
            radius = w;
            cout << "radius: " << w << endl;
        }
        else{
            radius = h;
            cout << "radius: " << h << endl;
        }
    }
    
};

class RectWin: public AppWindow{
public:
    int area;
    RectWin() : AppWindow(){
        this->x=this->y=w=h=0;
    }
    
    RectWin(int a, int b, int w, int h) : AppWindow(a,b,w,h){
    }
    
    RectWin(AppRect&r) : AppWindow(r){
    }
    
    void resize(int w, int h){
        this->w = w;
        this->h = h;
        area = w*h;
        cout << "area: " << area << endl;
    }
    
};


