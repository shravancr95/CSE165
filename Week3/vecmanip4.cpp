#include <string>
#include <vector>
#include <iostream>
using namespace std;

void remove(string s, vector<string> v){
    //cout << s << endl;
    string out = s;
    for(int i = 0; i < v.size(); i++){
        //cout << " '' " << v[i] << " '' is found at " << s.find(v[i]) << " to " << s.find(v[i]) + v[i].length()<< endl;
        while(out.find(v[i])!=-1){
            out = out.substr(0, out.find(v[i])) + out.substr(out.find(v[i]) + v[i].length(), out.length()-1);
            //cout << "after removing '' " << v[i] << " '' from " << s << " we have " << out << endl;
        }
    }
    cout << out << endl;
}

int main(){
    //vector<string> v;
    /*string s = "desktop";
    v.push_back("air");
    v.push_back("de");
    v.push_back("op");
    v.push_back("cat");
    remove(s,v);*/

    string s;
    vector<string> v;
    while(true){
        cin>>s;
        if(s == "quit"){
            break;
        }
        if(s.length() <= 3){
            v.push_back(s);
        }
        else{
            remove(s,v);
        }
    }
    
    return 0;
    
}