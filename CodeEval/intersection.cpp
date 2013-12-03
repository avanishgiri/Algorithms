#include <iostream>
#include <fstream>
#include <stdlib.h>
// #include <sstream>

using namespace std;

int main(int argc, char **argv){
	ifstream file;
	file.open(argv[1]);
	string s1, s2;
	int s1_max, s2_max, s1_min, s2_min;
	while (!file.eof()) 
	{
		getline(file, s1,';');
		getline(file, s2,'\n');
		s1_max = s1[s1.length()-1] - '0' + ((s1[s1.length()-2] - '0') * 10);
		s1_min = s1[1] - '0' + ((s1[0] - '0') * 10);
		s2_max = s2[s2.length()-1] - '0' + ((s2[s2.length()-2] - '0') * 10);
		s2_min = s2[1] - '0' + ((s2[0] - '0') * 10);

		cout << s1_min << endl << s2_min << endl;
		cout << "-------------" << endl;
		cout << s1 << endl;
		cout << s2 << endl;
		cout << "-------------" << endl;
		for(int i = min(s2_max,s1_max); i <= max(s1_min,s2_min); i++){
			cout << i;
			if(i < max(s1_min,s2_min))
				cout << ',';
		}
		cout << endl;
	}
}