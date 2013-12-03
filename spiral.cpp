#include <iostream>
#include <iomanip>

using namespace std;

void spiral_print(int **array, int n, int m)
{
	
	

}

int main()
{
	int array[5][5];
	for(int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			array[i][j] = i*5 + j;


	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
			cout << left << setw(4) << array[i][j];
		cout << endl;
	}
}
