#include <iostream>
#include <string>
#include <fstream>

std::string no_punct(std::string s){
	std::string result = "";
	for(int i = 0; i < s.size(); i++){
		if(!ispunct(s[i])){
			result+=tolower(s[i]);		
		}
	}
	return result;
}

int main(){
	std::string user;
	std::cin >> user;
	//std::cout << "You entered " << user << std::endl;
	std::ifstream file("words.txt");
	std::string s;
	int counter = 0;	
	while(file>>s){
		//std::cout << no_punct(s) << std::endl;
		if(user.compare(no_punct(s))==0){
			//std::cout << "user: " << user << " read from file: " << no_punct(s) << std::endl;
			
			counter++;
		}
	}
	file.close();
	std::cout << counter << std::endl;
	return 0;
}

