#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
    ifstream f("code.cpp");
    string line;
    vector <string> list;
    while(!f.eof()){
        getline(f, line);
        list.push_back(line);
    }
    int counter = 0;
    for(int i = list.size()-1; i >= 0; i--){
            cout << counter << ": " << list[i] << endl;
            counter++;
    }
	return 0;

}
