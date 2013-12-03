#include <iostream>
#include <gmp.h>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
	ifstream file;
	file.open(argv[1]);
	string test;
	int n, p1, p2;
	while (!file.eof()) 
	{
		getline(file, test);
		stringstream ss(test);
		ss >> n;
		ss.ignore();
		ss >> p1;
		ss.ignore();
		ss >> p2;
		// cout << (n >> (p1-1) & 1) << endl;
		// cout << (n >> (p2-1) & 1) << endl;

		if((n >> (p1-1) & 1) == (n >> (p2-1) & 1) )
			cout << "true" << endl;
		else
			cout << "false" << endl;
	}
}
