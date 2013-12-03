#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;
void bottomLeft(string** array, int x1, int y1, int x2, int y2);

void topRight(string **array, int x1, int y1, int x2, int y2){
	for(int i = x1; i<= x2; i++)
		cout << array[y1][i] << " ";

	for(int i = y1 + 1; i <= y2; i++)
		cout << array[i][x2] << " ";

	if(x2-x1 == 0 || y2-y1 == 0)
		return;
	else
		bottomLeft(array, x1, y1+1, x2-1, y2);
}

void bottomLeft(string** array, int x1, int y1, int x2, int y2){
	for(int i = x2; i >= x1; i--)
		cout << array[y2][i] << " ";

	for(int i = y2 - 1; i >= y1; i--)
		cout << array[i][x1] << " ";

	if(x2-x1 == 0 || y2-y1 == 0)
		return;
	else
		topRight(array, x1+1, y1, x2, y2-1);
}

void spiralPrint(string **array, int num_rows, int num_cols){
	topRight(array,0,0,num_cols-1,num_rows-1);
}

int main(int argc, char ** argv){
	ifstream file;
	file.open(argv[1]);
	int num_rows,num_cols;
	string lineBuffer;

	while (!file.eof()) 
	{
	   getline(file, lineBuffer);
	   if (lineBuffer.length() == 0)
	   		continue; //ignore all empty lines
	   else 
	   {
	   		stringstream ss(lineBuffer);
	   		ss >> num_rows;
	   		ss.ignore();
	   		ss >> num_cols;
	   		ss.ignore();

			string **array = new string*[num_rows];

			for(int i = 0; i < num_rows; i++)
				array[i] = new string[num_cols];

			for(int i = 0; i < num_rows; i++)
				for(int j = 0; j < num_cols; j++)
					ss >> array[i][j];

			spiralPrint(array, num_rows, num_cols);
			cout << endl;
		}
	}
}