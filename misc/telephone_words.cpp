#include <iostream>

using namespace std;

const string mappings[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};


void print_telewords(string number, int index, char *final){
	if(index == number.length())
		cout << final << endl;
	else{
		string letters = mappings[number[index] - '0'];
		int len = letters.length();
		for(int i = 0; i < len; i++){
			final[index] = letters[i];
			print_telewords(number, index+1,final);
		}
	}
}

int main(){
	string input = "234";
	int n = input.length();
	char s[n+1];
	s[n] = 0;
	print_telewords(input,0,s);
	
}
