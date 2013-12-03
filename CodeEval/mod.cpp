#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
	ifstream file;
	file.open(argv[1]);
	string test;
	int a, b;
	while (!file.eof()) 
	{
		getline(file,test);	
		stringstream ss(test);
		ss >> a;
		ss.ignore();
		ss >> b;
		if (a < b)
			cout << a << endl;
		else
			cout << a - b * (a/b) << endl;
	}
}