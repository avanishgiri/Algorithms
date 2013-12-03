#include <iostream>

using namespace std;

void counting_sort(int array[], int max, int length){
	int counts[max+1];
	int aux[length];
	
	for(int i = 0; i < max+1; i++){
		counts[i] = 0;	
	}
	for(int i = 0; i < length; i++){
		counts[array[i]] += 1;
	}
	for(int i = 1; i < max+1; i++){
		counts[i] = counts[i-1] + counts[i];
	}
	for(int i = length-1; i >= 0; i--){
		aux[ counts[ array[i] ]-1 ] = array[i];
		counts[array[i]]--;
	}
	for(int i = 0; i < length; i++){
		array[i] = aux[i];
	}
}

int main(){
 int array[] = {10, 1, 4, 5, 2, 1, 2, 1, 3, 9};
 counting_sort(array,10,10);
 for(int i = 0; i < 10; i++)
	 cout<<array[i] << " ";

 cout << endl;
}
