
#include <vector>
#include <iostream>
#include <string>
using namespace std;

bool contains_string(vector<string> v, string s){
    for(int i = 0; i < v.size(); i++){
        if(v[i] == s){
            return true;
        }
    }
    return false;
}

int main(){
    vector< vector<string> > v;
    string s;
    int string_size;
    //initialize the vector so that it contains string vectors
    for(int i = 0; i < 10; i++){
        v.push_back( vector<string>() );
    }
    //add words
    while(true){
        cin >> s;
        if(s == "quit"){
            break;
        }
        else{
            string_size = s.length();
            if(!contains_string(v[string_size], s)){
                v[string_size].push_back(s);
            }
        }
    }
    //print
    for(int i = 0; i < v.size(); i++){
        //cout << "vector at index " << i << ": ";
        for(int k =0; k < v[i].size(); k++){
            cout << v[i][k] << " ";
        }
        if(v[i].size() != 0){
            cout << endl;
        }
    }
    
    return 0;
}