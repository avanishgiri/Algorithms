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
		getline(file, test);
		stringstream ss(test);
		ss >> a;
		ss.ignore();
		ss >> b;
		int c = b;
		for(int i = 2; c < a; i++){
			c = i * b;
		}
		cout << c << endl;
	}
}