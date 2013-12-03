#include <iostream>
using namespace std;

bool isSolved(string grid, int &index){
	for(int i = 0; i < 81; i++){
		if(grid[i] == '.'){
			index = i;
			return false;
		}
	}
	return true;
}

bool isPossible(string grid, int index, int num){
	for(int i = 0; i < 81; i++)
	{
		if(grid[i] != '.')
		{
			if( (i / 9 == index / 9) || (i % 9 == index % 9))
			{
				if(num == grid[i])
					return false;
			}
			if( i / 27 == index / 27 && ( (i%9)/3 == (index%9)/3 ) )
				if(num == grid[i])
					return false;
		}
	}
	return true;
}

void remove(string &str, char c){
	int len = str.length();
	for(int i = 0; i < len; i++)
	{
		if(str[i] == c)
		{
			str = str.substr(0,i) + str.substr(i+1,len);
			return;
		}
	}
}

char assign(string grid, int index){
	string possible = "123456789";
	for(int i = 0; i < 81; i++)
	{
		if( (i / 9 == index / 9) || (i % 9 == index % 9))
			remove(possible,grid[i]+48);
		if( i / 27 == index / 27 && ( (i%9)/3 == (index%9)/3 ) )
			remove(possible,grid[i]+48);
	}
	if(possible.length() == 1)
		return possible[0];
	else
		return '.';
}

bool solve(string grid){
	int index;
	if(isSolved(grid,index)) //sets index via pass by reference
	{
		cout << grid << endl << endl;
		return true;
	}


	grid[index] = assign(grid, index);
	if(grid[index] == '.')
		for(int i = 1; i <= 9; i++){
			if(isPossible(grid, index, i+48))
			{
				grid[index] = i + 48;
				//cout << grid << endl;
				if(solve(grid))
					return true;
				grid[index] = '.';
			}
		}
	else{
		cout << grid << endl;
		if(solve(grid))
			return true;
		grid[index] = '.';
	}
	
	return false;
}

void replaceZeros(string& str)
{
	int len = str.length();
	for(int i = 0; i < len; i++)
		if(str[i] == '0')
			str[i] = '.';
}
#include <fstream>
int main(int argc, char ** argv){
	ifstream tests;
	tests.open(argv[1]);
	while(!tests.eof()){
		string grid;
		tests >> grid;
	  replaceZeros(grid);
		solve(grid);
	}
}
