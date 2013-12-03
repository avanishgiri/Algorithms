#include <iostream>
#include <fstream>
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
		if(values[index].length() > values[parent(index)].length()){
			swap(values[index], values[parent(index)]);
			bubble_up(parent(index));
		}
	}

	void bubble_down(int index){
		int c = index * 2;
		int min_index = index;


		for(int i = 0; i <= 1; i++)
			if ( (c+i) <= this->size )
				if(values[min_index].length() < values[c+i].length())
					min_index = c+i;

		if(min_index != index){
			swap(values[index], values[min_index]);
			bubble_down(min_index);
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

	void print(){
		for(int i = 1; i <= size; i++){
			cout << values[i] << endl;
		}
	}

	T dequeue(){
		T min;
		if(this->size == 0)
		{
			return NULL;
		}
		else {
			min = values[1];
			values[1] = values[size--];
			bubble_down(1);
		}
		return min;
	}

	bool empty(){
		return true;
	}
};

int main(int argc, char ** argv){
	ifstream file;
	file.open(argv[1]);
	int x;
	Heap<string> h;
	file >> x;
	string lineBuffer;
	while (!file.eof()) 
	{
	   getline(file, lineBuffer);
	   if (lineBuffer.length() == 0)
	       continue; //ignore all empty lines
	   else 
	   {
	       h.insert(lineBuffer);
	   }
	}
	for(int i = 0; i < x; i++)
		cout << h.dequeue() << endl;
}