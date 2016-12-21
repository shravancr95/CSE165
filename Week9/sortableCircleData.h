#include <vector>
using namespace std;
class Sortable {
    
public:
    virtual bool compare (const Sortable * s) = 0;
    virtual void print () = 0;
    virtual ~Sortable(){
        cout << "-Sortable()" << endl;
        //delete this;
    }
};

class Data /*: public Sortable*/{
public:
    vector<Sortable*>v;
    
    ~Data(){
        for(int i = 0; i < v.size(); i++){
            delete v[i];
        }
        cout << "-Data()" << endl;
    }
    
    void add(Sortable*s){
        v.push_back(s);
    }
    
    bool compare(const Sortable*s){
        cout << "calling data.h " << endl;
        //return this->compare(s);
        /*if (this < s){
         return true;
         }
         return false;*/
    }
    
    void remove(int index){
        if(v.size() == 0){
            cout << "Empty Dataset" << endl;
        }
        else if (index > v.size()-1){
            cout << "Index out of bounds" << endl;
        }
        else{
            v.erase(v.begin()+index);
        }
    }
    
    void print(){
        if(v.size() == 0){
            cout << "Dataset Empty" << endl;
        }
        else{
            for(int i = 0; i < v.size(); i++){
                //cout << "Circle with radius " << v[i]->r << " and area of " << v[i]->area() << endl;
                v[i]->print();
                //cout << v[i] << endl;
            }
            cout << endl;
        }
        
    }
    
    //Selection Sort
    
    /*void sort(){
     int min = 0;
     int min_loc = 0;
     for(int i = 0; i < v.size(); i++){
     min = INT_MAX;
     for (int k = i; k < v.size();k++){
     if (v[k] < min){
     min = v[k];
     min_loc = k;
     }
     }
     v[min_loc] = v[i];
     v[i] = min;
     }
     }*/
    
    //Bubble sort
    
    void sort(){
        int n = v.size();
        Sortable*temp;
        for(int i =0; i < n-1; i++){
            for(int j = 0; j < n-i-1; j++){
                if (v[j+1]->compare(v[j])){
                    //cout << "swapped element " << j << " and " << j+1 << "." << endl;
                    temp = v[j];
                    v[j] = v[j+1];
                    v[j+1] = temp;
                }
            }
        }
    }
};

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
    
    virtual ~Circle(){
        cout << "-Circle()" << endl;
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
