#include <iostream>
using namespace std;

class AppRect{
public:
    int x, y;
    int h, w;
    
    AppRect(){
        x=0;
        y=0;
        w=0;
        h=0;
    }
    
    AppRect(int x, int y, int width, int height){
        this->x = x;
        this->y = y;
        h = height;
        w = width;
    }
};


class AppWindow{
public:
    AppRect a_rect;
    // int x, y, w, h;
    AppWindow(){
        //this->x=this->y=w=h=0;
    }
    AppWindow(int a, int b, int width, int height){
        //   x = a;
        //   y = b;
        //   w = width;
        //   h = height;
        a_rect = AppRect(a,b,width,height);
    }
    AppWindow(const AppRect&r){
        a_rect = r;
    }
    const AppRect& rect(){
        return a_rect;
    }
    virtual void resize (int w, int h ){
        //cout << "resize of appwindow" << endl;
        a_rect.w = w;
        a_rect.h = h;
    }
};

class CircleWin: public AppWindow{
public:
    CircleWin() : AppWindow(){
    }
    
    CircleWin(int a, int b, int w, int h) : AppWindow(a,b,w,h){
        
    }
    
    CircleWin(const AppRect&r) : AppWindow(r){
        
    }
    
    void resize(int w, int h){
        if(w>h){
            cout << "radius: " << h << endl;
        }
        else if (h>w){
            cout << "radius: " << w << endl;
        }
        else{
            cout << "radius: " << h << endl;
        }
    }
    
};

class RectWin: public AppWindow{
public:
    RectWin() : AppWindow(){
        
    }
    
    RectWin(int a, int b, int w, int h) : AppWindow(a,b,w,h){
    }
    
    RectWin(const AppRect&r) : AppWindow(r){
    }
    
    void resize(int w, int h){
        cout << "area: " << w*h << endl;
    }
    
};