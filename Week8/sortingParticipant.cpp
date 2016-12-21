#include <iostream>
#include <string>
#include "Sortable.h"
#include "Data.h"
#include "Participant.h"

using namespace std;


int main(int argc, const char * argv[])
{
    string name;
    int age;
    double score;
    
    //int n;
    //cin >> n;
    
    Data myData;
    
    /*for (int i = 0; i < n; i++) {
        cin >> name >> age >> score;
        myData.add(new Participant(name, age, score));
    }*/
    
    myData.add(new Participant("John", 26, 3.7));
    myData.add(new Participant("Alan", 26, 3.7));
    myData.add(new Participant("Jake", 25, 3.7));
    myData.add(new Participant("Pete", 30, 3.9));
    
    myData.print();
    
    myData.sort();
    
    myData.print();
    return 0;
}

