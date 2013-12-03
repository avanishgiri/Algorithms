#include "../DataStructures/queue.h"

extern long long counter;

void merge(int *array, int low, int middle, int high){
	Queue q1, q2;
	for(int i = low; i <= middle; i++)
		q1.enqueue(array[i]);
	for(int i = middle + 1; i <= high; i++)
		q2.enqueue(array[i]);
	
	int i = low;
	while(!(q1.empty() || q2.empty()))
	{
		counter++;
		if(q1.peek() <= q2.peek())
			array[i++] = q1.dequeue();
		else
			array[i++] = q2.dequeue();
	}

	while(!q1.empty())
	{
		counter++;
		array[i++] = q1.dequeue();
	}

	while(!q2.empty())
	{
		counter++;
		array[i++] = q2.dequeue();
	}

}

void mergesort(int *array, int low, int high){
	int middle;

	if(low < high)
	{
		middle = (high + low)/ 2;
		mergesort(array, low, middle);
		mergesort(array, middle+1, high);
		merge(array, low, middle, high);
	}
}
/*
int main(){
	int array[4];
	for(int i = 0; i < 4; i++)
		array[i] = i - (i * i + i);
	for(int i = 0; i < 4; i++)
	  cout <<	array[i] << " ";
	cout << endl;
	mergesort(array, 0, 3);
	for(int i = 0; i < 4; i++)
	  cout <<	array[i] << " ";
}
*/
