/#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	vector<int> v;
	int k;
    
    while(true){
        cin >> k;
        if(k == 0){
            break;
        }
        else if(k > 0){
            v.push_back(k);
        }
        else{
            for(int i = 0; i < v.size(); i++){
                if(v[i] == k*-1){
                    v.erase(v.begin()+i);
                    i--;
                }
            }
        }
    }
    
    int sum = 0;
    cout << v.size() << " ";
    for(int i =0; i < v.size();i++){
        sum+=v[i];
    }
    cout << sum << endl;
	
}
