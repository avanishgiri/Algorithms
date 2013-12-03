#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){
	ifstream file;
	file.open(argv[1]);
	string test;
	int n;
	while (!file.eof()) 
	{
		n = 0;
		getline(file, test);
		for(int i = 0; i < test.length(); i++)
			n += test[i] - '0';
		cout << n << endl;
	}	
}