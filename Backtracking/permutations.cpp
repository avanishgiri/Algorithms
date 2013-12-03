#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

vector<string> p;

void insertion_sort(string& s){
	int l = s.length();
	for(int i = 1; i < l; i++){
		int j = i-1;
		while(j >= 0)
		{
			if((int)s[i] < (int)s[j]){
				swap(s[i],s[j]);
			}
			j--;
		}
	}
}

void perms(string soFar, string rest){
	if(rest == "")
		p.push_back(soFar);
	else{
		for(int i = 0; i < rest.length(); i++){
			string remaining = rest.substr(0,i) + rest.substr(i+1);
			perms(soFar + rest[i], remaining);
		}
	}
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
	   insertion_sort(lineBuffer);
	   if (lineBuffer.length() == 0)
	   		continue; //ignore all empty lines
	   else
	   		permutations(lineBuffer);

	   vector<string>::iterator it = p.begin();
	   cout << *it;
	   while(++it != p.end()){
	   	cout << "," << *it;
	   }
	   cout << endl;
	   p.clear();
	}
}