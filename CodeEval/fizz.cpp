#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char **argv){
	ifstream file;
	file.open(argv[1]);
	string test;
	int a, b, n;
	while (!file.eof()) 
	{
		getline(file, test);
		istringstream(test) >> a >> b >> n;
		for(int i = 1; i <= n; i++){
			if(!(i % a || i % b))
				cout << "FB";
			else if(!(i % a))
				cout << "F";
			else if(!(i % b))
				cout << "B";
			else
				cout << i;
			if(!(i == n))
				cout << " ";
		}
		cout << endl;
	}
}