#ifndef STASH_H
#define STASH_H

#include <cassert>
#include <iostream>
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

Vec Vec::null = Vec();

class Rect{
    
public:
    Vec A,B,C,D;
    float height, width;
    Rect();
    Rect(float a, float b, float w, float h){
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

struct RectStash {
    int size;      // Size of each space
    int quantity;  // Number of storage spaces
    int next;      // Next empty space
    int num_inc = 0;
    int num_realloc = 0;
    
    // Dynamically allocated array of bytes:
    unsigned char* storage;
    
    // Functions!
    void initialize(int sz){
        size = sz;
        quantity = 0;
        storage = 0;
        next = 0;
    }
    
    void cleanup(){
        if(storage != 0) {
            std::cout << "freeing storage" << std::endl;
            delete []storage;
        }
    }
    
    int add(const void* element){
        if(next >= quantity) // Enough space left?
            inflate(100);
        
        // Copy element into storage,
        // starting at next empty space:
        int startBytes = next * size;
        unsigned char* e = (unsigned char*)element;
        
        for(int i = 0; i < size; i++)
            storage[startBytes + i] = e[i];
        next++;
        
        return(next - 1); // Index number
    }
    
    void* fetch(int index){
        // Check index boundaries:
        assert(0 <= index);
        
        if(index >= next)
            return 0; // To indicate the end
        
        // Produce pointer to desired element:
        return &(storage[index * size]);
    }
    
    int count() {
        return next; // Number of elements in CStash
    }
    
    void inflate(int increase){
        assert(increase > 0);
        
        int newQuantity = quantity + increase;
        int newBytes = newQuantity * size;
        int oldBytes = quantity * size;
        unsigned char* b = new unsigned char[newBytes];
        
        for(int i = 0; i < oldBytes; i++)
            b[i] = storage[i]; // Copy old to new
        
        delete []storage; // Old storage
        storage = b; // Point to new memory
        quantity = newQuantity;
    }
}; ///:~

#endif

int main(){
    RectStash*r = new RectStash();
    r->initialize(sizeof(Rect));
    float x,y,w,h;
    //float vec_x, vec_y;
    int counter = 0;
    while(true){
        cin >> x;
        cin >> y;
        cin >> w;
        cin >> h;
        if(h>0 && w>0){
            r->add(new Rect(x,y,w,h));
            //cout << ((Rect*)(r->fetch(counter)))->A.x << " " << ((Rect*)(r->fetch(counter)))->A.y << endl;
            counter++;
        }
        else
            break;
    }
    bool in;
    vector <Vec> vec_of_vec;
    Vec v;
    Rect*temp;
    while(true){
        //v = new Vec();
        cin >> v.x;
        cin >> v.y;
        
        if (v.x == -99 && v.y == -99){
            break;
        }
        else{
            vec_of_vec.push_back(v);
        }
    }
    
    for(int i = 0; i < vec_of_vec.size(); i++){
        for(int j = 0; j < counter; j++){
            //cout << vec_of_vec[i]->x << " " << vec_of_vec[i]->y << endl;
            //cout << "enters loop" << endl;
            //((Rect*)(r->fetch(i))
            if(((Rect*)(r->fetch(j)))->contains(vec_of_vec[i])){
                cout << "in ";
            }
            else{
                cout << "out ";
            }
        }
        cout << endl;
    }
}
