#include <iostream>

using namespace std;

void merge(int * array, int low, int middle, int high){
	int buffer[high-low+1];

	int i = low, j = middle+1, k = 0;

	while(i <= middle && j <= high){
		if(array[i] <= array[j])
			buffer[k++] = array[i++];
		else
			buffer[k++] = array[j++];
	}

	while(i <= middle)
		buffer[k++] = array[i++];
	while(j <= high)
		buffer[k++] = array[j++];

	for(int i = low, j=0; i <= high; i++,j++)
		array[i] = buffer[j];
}

int * msort(int * array, int low, int high){
	int middle;
	if(low < high){
		middle = (high + low) / 2;
		msort(array,low, middle);
		msort(array, middle+1, high);
		merge(array,low,middle,high);
	}
}

int main(){
	int array[4];
	for(int i = 4, j = 0; i >= 1; i--, j++)
		array[j] = i;
	for(int i = 0; i < 4; i++)
		cout << array[i] << endl;
	cout << endl;
	msort(array,0,3);
	for(int i = 0; i < 4; i++)
		cout << array[i] << endl;
}
