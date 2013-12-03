#include <iostream>

using namespace std;
#define N 4
int counter = 0;

bool legal_move(int x, int y, int array[N+2][N+2]){
	bool ret = (array[x][y] == 1);
	array[x][y] = 0;
	return ret;
}

/*
void print_array(int array[N+2][N+2]){
	for(int i = 0; i < N+2; i++){
		for(int j = 0; j < N+2; j++)
			cout << array[i][j] << " ";
	  cout << endl;
	}
	cout << endl << endl;
}
*/

void print_paths(int x, int y, int n, int m, int array[N+2][N+2]){
	if(x == n && y == m){
		//print_array(array);
		counter++;
	}
	else {
		int dx = 1;
		int dy = 0;
		for(int i = 0; i < 4; i++){
			if(legal_move(x + dx, y + dy, array)){
				print_paths(x + dx, y + dy, n, m, array);
				array[x+dx][y+dy] = 1;
			}
			swap(dx,dy);
			if(i == 1)
				dx = -dx;
		}
	}
}

int main(){

	int array[N+2][N+2];

	for(int i = 1; i < N+1; i++)
		for(int j = 1; j < N+1; j++)
			array[i][j] = 1;

	for(int i = 0; i < N+2; i++)
		array[0][i] = array[i][0] = array[N+1][i] = array[i][N+1] = 0;

//print_array(array);
	array[1][1] = 0;  //Set start cell to be seen.
	print_paths(1,1,N,N,array);
	cout << counter << endl;
}


