#include <iostream>
using namespace std;

template <class T>
class Heap{
private:
	int size;
	int max_size;
	T *values;

	int parent(int index){
		if(index == 1)
			return -1;
		else
			return index/2;
	}

	void bubble_up(int index){
		if(parent(index) == -1)
			return;
		if(values[index] < values[parent(index)]){
			swap(values[index], values[parent(index)]);
			bubble_up(parent(index));
		}
	}
public:
	Heap(int max_size = 1000){
		this->size = 0;
		this->max_size = max_size;
		this->values = new T[this->max_size+1];
	}
	void insert(T value){
		if(this->size >= this->max_size){
			cout << "Warning. Heap overflow" << endl;
		}
		else {
			values[++this->size] = value;
			bubble_up(this->size);
		}
	}

	T dequeue(){

	}
};