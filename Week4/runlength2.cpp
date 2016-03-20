#include <iostream>
#include <vector>
#include <string>
#include <cassert>
using namespace std;

struct Stash {
    int size;      // Size of each space
    int quantity;  // Number of storage spaces
    int next;      // Next empty space
    int num_inc;
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
    
    int add(const void* element, int num_incr){
        if(next >= quantity) // Enough space left?
            inflate(num_incr);
        
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
        num_realloc++;
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

int main(){
    
    //std::vector<pair> v;
    //string final = "";
    int increase;
    cin>>increase;
    
    
    Stash*s = new Stash();
    s->num_inc = increase;
    
    char in;
    int n;
    char nextline = '\n';
    s->initialize(sizeof(char));
    //pair*p;
    
    while(true){
        cin >> in;
        cin >> n;
        if(in == '&' && n == 99){
            break;
        }
        if(n>0){
            for(int i = 0; i < n; i++){
                s->add(&in, increase);
            }
        }
        if(n<0){
            for(int i = 0; i < n*-1; i++){
                s->add(&in, increase);
            }
            s->add(&nextline, increase);
        }
    }
    
    for(int i = 0; i < s->next; i++){
        cout << *((char*)s->fetch(i));
    }
    
    cout << s->num_realloc << endl;
    cout << s->quantity << endl;
    
    /*char c = ' ';
     int k = 0;
     
     while(true){
     v.push_back(pair());
     std::cin >> v[v.size()-1].key;
     std::cin >> v[v.size()-1].num;
     if(v[v.size()-1].num == -2){
     break;
     }
     //v.push_back(pair())
     }
     
     for(int i = 0; i < v.size()-1; i++){
     if(v[i].num == -1){
     std::cout << std::endl;
     }
     for(int k = 0; k < v[i].num; k++){
     std::cout << v[i].key;
     }
     //std::cout << v[i].key << " " << v[i].num << std::endl;
     }*/
    return 0;
}
