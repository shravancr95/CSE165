using namespace std;
#include <vector>
#include <climits>
#include "Sortable.h"

class Data : public Sortable {
public:
    vector<Sortable*>v;
    
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
    
    void print(){
        for(int i = 0; i < v.size(); i++){
            //cout << "Circle with radius " << v[i]->r << " and area of " << v[i]->area() << endl;
            v[i]->print();
            //cout << v[i] << endl;
        }
        cout << endl;
        
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