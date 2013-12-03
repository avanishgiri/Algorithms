#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

int main(int argc, char **argv){
	ifstream file;
	file.open(argv[1]);
	string test;
	int i;
	while (!file.eof()) 
	{
		getline(file, test);
		int j = test.length()-1;
		for(i = j-2; i >= 0; i--){
			if(test[i] == test[j]){
				cout << i << endl;
				break;
			}
		}
		if(i == -1)
			cout << i << endl;
	}
}