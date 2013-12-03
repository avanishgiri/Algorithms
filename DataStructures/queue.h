#include "doubly.h"

class Queue{
	DoublyLinkedList *elems;
	public:
		Queue(){
			this->elems = new DoublyLinkedList;
		}

		void print(){
			this->elems->printList();
		}
			
		void enqueue(int data){
			this->elems->insert(data);
		}

		bool empty(){
			if(!this->elems->getTail())
				return true;
			return false;
		}

		int dequeue(){
			if(this->empty())
				return 0;
			else
				return this->elems->removeTail();
		}

		int peek(){
			if(!this->empty())
				return this->elems->getTail()->data;
		}
};
