#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

unsigned long fib(int n){
	unsigned long long a = 0;
	unsigned long long b = 1;
	
	if(n == 0)
		return 0;

	for(int i = 0; i < n; i++){
		int temp = a + b;
		a = b;
		b = temp;
	}
	return b;
}

int main(int argc, char** argv){
	ifstream file;
	file.open(argv[1]);
	while (!file.eof())
	{
		string input;
		getline(file, input);
		unsigned long long n;
		stringstream ss(input);
		if (input.length() == 0)
			continue; //ignore all empty lines
		else
		{
			ss >> n;
			cout << fib(n) << endl;
		}
	}
}

