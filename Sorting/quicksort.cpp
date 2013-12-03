#include <iostream>
#include <stdlib.h>
#include "mergesort.h"
#include <sys/time.h>
using namespace std; 

long long counter = 0;
int compare (const void * a, const void * b)
{
	  return ( *(int*)a - *(int*)b );
}


int partition(int *array, int low, int high){
	int firsthigh = low;
	int pivot = high;

	for(int i = low; i < high; i++)
	{
		counter++;
		if(array[i] < array[pivot])
		{
			swap(array[i], array[firsthigh]);
			firsthigh++;
		}
	}
	swap(array[pivot],array[firsthigh]);
	return firsthigh;
}

void quicksort(int *array, int low, int high){
	int p;
	if(low < high)
	{
		p = partition(array, low, high);
		quicksort(array, low, p-1);
		quicksort(array,p+1,high);
	}
}

int main(){
	int array[100000];
	for(int i = 0; i < 100000; i++)
		array[i] = i;

	struct timeval start, end;

	for(int i = 0; i < 100000; i++)
		cout << array[i] << " ";
	//mergesort(array, 0, 100000);
	gettimeofday(&start, NULL);
	quicksort(array, 0, 99999);

	
	gettimeofday(&end, NULL);
	long long time =   (end.tv_sec * (unsigned int)1e6 +   end.tv_usec) - 
		                 (start.tv_sec * (unsigned int)1e6 + start.tv_usec);

	for(int i = 0; i < 100000; i++)
		cout << array[i] << " ";
	cout << endl;

	cout << endl << endl << time/1000000.0 << endl;
	cout << endl << counter;
}
