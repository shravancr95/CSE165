
#include "Sortable.h"
using namespace std;
class Participant : public Sortable {
public:
    //static void (*A::cb)(int a, char c) = NULL;
    //static bool (*comp_cb)(const Participant*, const Participant*);

    int age;
    string name;
    double score;
    
    Participant(){
        age = 0;
        name = "";
        score = 0;
    }
    
    Participant(string n, int a, double s){
        age = a;
        name = n;
        score = s;
    }
    
    bool compare(const Sortable*s){
        //Participant*p = (Participant*)s;
        //This is for Sortable Objects III
        return this->compareParticipants((Participant*)(s));
        //cout << "calling compare" << endl;
        //This is for sortable objects IV
        //return !comp_cb(this, (Participant*)s);
    }
    
    bool compareParticipants(Participant*p){
        if(this->score > p->score){
            //this score is greater
            //cout << this->name << " & " << p->name << " score checked" <<endl;
            return true;
        }
        if(this->age < p->age && this->score == p->score){
            //cout << this->name << " & " << p->name << " age checked. " <<endl;
            //this is older
            return true;
        }
        if(this->name < p->name && this->score == p->score && this->age == p->age){
            //cout << this->name << " & " << p->name << " name checked. " << endl;
            //this is first alphabetically
            return true;
        } 
        return false;
    }
    
    virtual void print(){
        cout << this->name << "\t" << this->age << "\t" << this->score << endl;
    }

};
