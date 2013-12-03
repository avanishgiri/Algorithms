#include <iostream>

using namespace std;
#define N 4
#define LEGAL 1
#define ILLEGAL 0
int counter = 0;

void count_paths(int x, int y, int n, int m, int array[N+2][N+2]){
	if(x == n && y == m){
		counter++;
	}
	else {
		int dx = 1, dy = 0;
		for(int i = 0; i < 4; i++){
			if(array[x+dx][y+dy] == LEGAL){
				array[x+dx][y+dy] = ILLEGAL;
				count_paths(x + dx, y + dy, n, m, array);
				array[x+dx][y+dy] = LEGAL;
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
			array[i][j] = LEGAL;

	for(int i = 0; i < N+2; i++)
		array[0][i] = array[i][0] = array[N+1][i] = array[i][N+1] = ILLEGAL;

	array[1][1] = ILLEGAL; //Set start sell to be seen.
	count_paths(1,1,N,N,array);
	cout << counter << endl;
}


