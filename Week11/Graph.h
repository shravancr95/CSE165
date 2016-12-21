#include "Vertex.h"
#include <string>
using namespace std;

class Graph
{
public:
    /*! A collection of vertices */
    vector<Vertex*> items;
    
    /*! A method to add a vertex to the items vector */
    void add(Vertex* a){
        items.push_back(a);
        a->ref();
        //insert your code here
        
    }
    
    /*! A method to display the graph as pairs of vertices */
    void print (){
        for (int i = 0; i < items.size(); i += 2) {
            cout << items[i]->getLabel() << " - " << items[i + 1]->getLabel() << endl;
        }
        //insert your code here
        
    }
    
    /*! A method to free up all the space taken up by the graph */
    void deleteAll(){
        
        for (int i = 0; i < items.size(); i++)
        {
            items[i]->unref();
        }
        //insert your code here
        
    }
};


