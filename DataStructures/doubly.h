#include <iostream>

using namespace std;

class ListNode {
	public:
		int data;
		ListNode *next;
		ListNode *prev;
};

class DoublyLinkedList {
	ListNode *head;
	ListNode *tail;

	public:
		DoublyLinkedList(){
			this->head = this->tail = NULL;
		}

		void insert(int data){
			ListNode *p = new ListNode;
			p->data = data;
			p->prev = NULL;
			if(!this->head)
			{
				this->head = this->tail = p;
				p->next = NULL;
			}
			else
			{
				p->next = this->head;
				this->head->prev = p;
				this->head = p;
			}
		}

		int removeTail(){
			ListNode *p = this->tail;
			this->tail = this->tail->prev;
			if(this->tail)
				this->tail->next = NULL;
			int data = p->data;
			delete p;
			return data;
		}

		void printList(){
			ListNode *p = this->head;
			while(p)
			{
				cout << p->data << endl;
				p = p->next;
			}
		}
		ListNode* getTail(){
			return this->tail;
		}
};
