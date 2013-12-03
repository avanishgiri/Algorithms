#include <iomanip>
#include <iostream>

using namespace std;
void bottomLeft(int** array, int x1, int y1, int x2, int y2);

void topRight(int **array, int x1, int y1, int x2, int y2){
	for(int i = x1; i<= x2; i++){
		cout << array[y1][i] << " ";
	}
	for(int i = y1 + 1; i <= y2; i++){
		cout << array[i][x2] << " ";
	}
	cout << endl;

	if(x2-x1 > 0){
		bottomLeft(array, x1, y1+1, x2-1, y2);
	}


}

void bottomLeft(int** array, int x1, int y1, int x2, int y2){
	for(int i = x2; i >= x1; i--){
		cout << array[y2][i] << " ";
	}
	for(int i = y2 - 1; i >= y1; i--){
		cout << array[i][x1] << " ";
	}
	cout << endl;

	if(y2-y1 > 0){
		topRight(array, x1+1, y1, x2, y2-1);
	}

}

void spiralPrint(int **array, int num_rows, int num_cols){
	topRight(array,0,0,num_cols-1,num_rows-1);
}

int main(){
	int num_rows = 10000, num_cols = 10000;
	int **array = new int *[num_rows];

	for(int i = 0; i < num_rows; i++)
		array[i] = new int[num_cols];

	for(int i = 0; i < num_rows; i++)
		for(int j = 0; j < num_cols; j++)
			array[i][j] = num_cols*i + j + 1;

	for(int i = 0; i < num_rows; i++){
		for(int j = 0; j < num_cols; j++)
			cout << left << setw(3) << array[i][j] << " ";
		cout << endl;
	}
	cout << endl << endl;

	spiralPrint(array, num_rows, num_cols);
}
