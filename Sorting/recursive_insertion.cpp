#include <iostream>

using namespace std;


void insertion_sort(int array[], int length){
	if(length == 1)
		return;
	else {
		insertion_sort(array, length-1);
		int i = length-2;
		int j = length-1;
		while(i >= 0 && array[j] < array[i]){
			swap(array[i],array[j]);
			j = i--;
		}
	}
}

int main(){
	int array[] = {4,3,2};
	for(int i = 0; i < 3; i++)
		cout << array[i] << ' ';
	cout << endl;
	insertion_sort(array,3);
	for(int i = 0; i < 3; i++)
		cout << array[i] << ' ';
	cout << endl;
	
}
