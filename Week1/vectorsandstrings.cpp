#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream f("code.cpp");
    string line;
    vector <string> list;
    string result = "";
    while(!f.eof()){
        getline(f, line);
        result += line;
    }

    cout << result;
    return 0;
    
}
