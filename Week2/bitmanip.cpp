#include <iostream>
#include <string>
#include <vector>
#include "Math.h"
using namespace std;

string reverse(string s){
    string out = "";
    for(int i = s.length()-1; i >= 0; i--){
        out+=s[i];
    }
    return out;
}

int main(){
    vector<int> bits;
    while(true){
        string user_input, flip_bits;
        int base_ten = 0;
        cin >> user_input;
        if(user_input == "-1"){
            break;
        }
        flip_bits = "";
        for(int i = 0; i < user_input.length(); i++){
            bits.push_back(user_input[i] - 48);
        }
        int k = 0;
        for(int i = user_input.length()-1; i >= 0; i--){
            base_ten += bits[i]*pow(2, k);
            k++;
        }
        for(int i = 0; i < bits.size(); i++){
            if(bits[i] == 1){
                flip_bits += '0';
            }
            else{
                flip_bits += '1';
            }
        }
        cout << base_ten << " " << reverse(user_input) << " " << flip_bits << endl;
        bits.clear();
    }
        return 0;
}