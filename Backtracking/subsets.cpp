#include <iostream>
using namespace std;
int counter = 0;

void subsets(string str, string rest)
{
	int length = rest.length();
	for(int i = 0; i < length; i++){
		string current = str + rest[i];
		string remaining = rest.substr(i+1);
		subsets(current,remaining);
	}
	cout << str << endl;
}

void subsets2(string str, string rest)
{
	int length = rest.length();
	if(length == 0)
	cout << str << endl;
	else { string current = str + rest[0];
		string remaining = rest.substr(1);
		subsets2(current, remaining);
		subsets2(str, remaining);
	}
}

void permute(string str, string rest)
{
	cout << counter++ << endl;
	int length = rest.length();
	if(length == 0)
		cout << str << endl;
	else{
		for(int i = 0; i < length; i++){
			string current = str + rest[i];
			string remaining = rest.substr(0,i) + rest.substr(i+1,length);
			permute(current, remaining);
		}
	}
}

void print_permutations(string str)
{
	permute("",str);
}

void print_subsets(string str)
{
	subsets2("",str);
}


int main(){
	print_subsets("ABCDEFGHIK");
}
