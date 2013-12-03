#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

long long choose(int n, int k, map< pair<int,int>, long long>& memo){
	pair<int,int> p = make_pair(n,k);
	if(memo[p])
		return memo[p];
	if(p.first == p.second || p.second == 0)
		memo[p] = 1;
	else
		memo[p] = choose(n-1,k-1,memo) + choose(n-1,k,memo);
	
	return memo[p];
}

int unoptimized_choose(int n, int k){
	if(n == k || k == 0)
		return 1;
	else
		return unoptimized_choose(n-1,k-1) + unoptimized_choose(n-1,k);
}

long long choose_driver(int n, int k){
	map< pair<int, int>, long long> memo;
	return choose(n,k,memo);
}

long long iterative_choose(int n, int k){
	long long array[n+2][n+2];
	for(int i = 0; i-2 < n; i++)
		for(int j = 0; j-2 < n; j++)
			array[i][j] = 0;

	for(int i = 1; i-2 < n; i++){
		array[i][1] = 1;
		array[i][i] = 1;
	}

	for(int i = 2; i-2 < n; i++)
		for(int j = 2; j-2 < n; j++)
			array[i][j] = array[i-1][j-1] + array[i-1][j];

/*	for(int i = 0; i-2 < n; i++){
		for(int j = 0; j-2 < n; j++)
			cout << setw(5) << left << array[i][j];
		cout << endl;
	}
*/
	cout << endl << endl << array[n+1][k+1] << endl;

}

int main(){
	iterative_choose(34,17);
	cout << choose_driver(34,17) << endl;
	cout << unoptimized_choose(34,17) << endl;
}
