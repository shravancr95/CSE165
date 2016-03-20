#include <iostream>
#include "math.h"
#include <vector>
#include <string>
using namespace std;

int main(){
	int input=0;
    vector <int> bits;
    while(true){
        cin >> input;
        if(input != -1){
            cout << hex << input << " ";
            string bin = "";
            while(input != 0){
                bits.push_back(input%2);
                input = input/2;
            }
            for(int i = bits.size()-1; i >= 0; i--){
                cout << bits[i];
            }
            cout << endl;
            bits.clear();
        }
        else{
            break;
        }
    }
}
