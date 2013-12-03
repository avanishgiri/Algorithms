#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char ** argv){
	ifstream file;
	file.open(argv[1]);
	string test;
	int a, b, n;
	while (!file.eof())
	{
		getline(file, test);
		for(int i = 0, j = test.length() - 1; i <= j; i++, j--){
			swap(test[i],test[j]);
		}
		for(int i = 0; i < test.length(); i++){
			int j = i;
			while(test[j] != ' ' && test[j] != '\0')
				j++;
			for(int k = i, l = j-1; k <= l; k++, l--){
				swap(test[k],test[l]);
			}
			i = j;
		}
		cout << test << endl;
	}
}