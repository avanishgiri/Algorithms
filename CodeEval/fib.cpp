#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
	ifstream file;
	file.open(argv[1]);
	string test;
	long long a, b, n, temp;
	while (!file.eof()) 
	{
		getline(file, test);
		stringstream ss(test);
		ss >> n;
		if(n == 0)
			cout << 0 << endl;
		else{
			a = 0, b = 1;
			for(int i = 1; i < n; i++){
				temp = b;
				b = a + b;
				a = temp;
			}
			cout << b << endl;
		}
	}
}