#include <iostream>
#include <string>
#include <vector>
#include "Math.h"
using namespace std;

int to_bin(string s){
    //string out = "";
    vector<int> bits;
    for(int i = 0; i < s.length(); i++){
        bits.push_back(s[i] - 48);
    }
    int sum = 0;
    int k = 0;
    for(int i = bits.size()-1; i >= 0; i--){
        sum += bits[i]*pow(2,k);
        k++;
        //cout << bits[i];
    }
    //cout << sum << endl;
    return sum;
    //cout << endl;
    
}

int main(){
    string in;
    //string in = "00000011000000010010X";
    cin >> in;
    //cout << "size: " << in.length() << endl;
    vector<string> num;
    
    string s = "";
    
    if(in.length()-1<8){
        //num.push_back(in.substr(0,in.length()-1));
        for(int i = 0; i < in.length()-1; i++){
            s+=in[i];
        }
        num.push_back(s);
        s = "";
    }
    else{
        
        for(int i = 0; i < in.length()-1; i++){
            if(i%8 == 0 && i>0){
                num.push_back(s);
                s = "";
            }
            s+=in[i];
        }
        num.push_back(s);
    }
    for(int i = 0; i < num.size(); i++){
        cout << to_bin(num[i]) << " ";
    }
    return 0;
}