#ifndef LA10_Vec_h
#define LA10_Vec_h

using namespace std;

class Vec {
public:
    float x;
    float y;

    Vec(){
        x = 0;
        y = 0;
    }
    
    Vec (float x, float y){
        this->x = x;
        this->y = y;
    }
    
    /*Vec operator + (const Vec & v){
        return Vec(x + v.x, y + v.y);
    }
    
    Vec operator - (const Vec & v){
        return Vec(x - v.x, y - v.y);
    }
    
    Vec operator * (const int&a){
        return Vec(a*x, a*y);
    }*/
    
    Vec operator + (const Vec & v){
        return Vec(x + v.x, y + v.y);
    }
    
    Vec operator - (const Vec & v){
        return Vec(x - v.x, y - v.y);
    }
    
    Vec operator * (const int&a){
        return Vec(a*x, a*y);
    }

    

};

ostream& operator<< (ostream& o, const Vec & v){
    o << "(" << v.x << ", " << v.y << ")";
    return o;
}

#endif
