#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
const string mappings[10] = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

vector<string> wow;

void print_telewords(string number, int index, char *final){
  if(index == number.length())
    wow.push_back(string(final));
  else{
    string letters = mappings[number[index] - '0'];
    int len = letters.length();
    for(int i = 0; i < len; i++){
      final[index] = letters[i];
      print_telewords(number, index+1,final);
    }
  }
}

int main(int argc, char** argv){
	ifstream file;
	file.open(argv[1]);
	while (!file.eof()) 
		 {
			 	 string input;
				 getline(file, input);
				 if (input.length() == 0)
						 continue; //ignore all empty lines
				 else 
				 {
						 int n = input.length();
						 char s[n+1];
						 s[n] = 0;
						 print_telewords(input,0,s);
						 cout << endl;
						 vector<string>::iterator it; 
							for(it = wow.begin(); it != --wow.end(); it++){
								cout << *it << ",";
							}
							cout << *(it) << endl;
							wow.clear();
				 }
	}
}
