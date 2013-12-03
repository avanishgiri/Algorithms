#include <iostream>

using namespace std;

void subs2(string soFar, string rest){
	int length = rest.length();
	for(int i = 0; i < length; i++){
		string remaining = rest.substr(i+1);
		string current = soFar + rest[i];
		subs2(current, remaining);
	}
	cout << soFar << endl;
}

void subs(string soFar, string rest){
	if(rest == "")
		cout << soFar << endl;
	else{
		string current = rest.substr(0,1);
		string remaining = rest.substr(1);
		subs(soFar + current, remaining);
		subs(soFar, remaining);
	}
}

void perms(string soFar, string rest){
	if(rest == "")
		cout << soFar << endl;
	else{
		for(int i = 0; i < rest.length(); i++){
			string remaining = rest.substr(0,i) + rest.substr(i+1);
			perms(soFar + rest[i], remaining);
		}
	}
}
void subsets(string str){
	subs2("",str);
}

void permutations(string str){
	perms("",str);
}

int main(int argc, char ** argv){
	ifstream file;
	file.open(argv[1]);
	string lineBuffer;

	while (!file.eof()) 
	{
	   getline(file, lineBuffer);
	   if (lineBuffer.length() == 0)
	   		continue; //ignore all empty lines
	   else 
	   		permutations(lineBuffer);
	}
}