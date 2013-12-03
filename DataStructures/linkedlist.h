#include <stdio.h>
#include <stdlib.h>
typedef struct list list;

void print_int(int num){
	printf("%d\n",num);
}

struct list {
	int data;
	struct list *next;
};

void insert(list **l, int value){
	list *p;
	p = malloc(sizeof(list));

	p->data = value;
	p->next = *l;
	*l = p;
}

void delete(list **l, int value){
	list *p = *l;

	if(p->data == value){
		*l = p->next;
		free(p);
	}

	for(;p->next; p = p->next){
		if(p->next->data == value){
			list *dead_node = p->next;
			p->next = dead_node->next;
			free(dead_node);
			break;
		}
	}
}

list *search(list *l, int value){
	if(l)
		if(l->data == value)
			return l;
		else
			return search(l->next, value);
	return 0;
}

void print_list(list *l){
	list *p;
	for(p = l; p; p = p->next){
		printf("%d\n",p->data);
	}
	printf("\n\n");
}

void reverse(list **l){
	list *previous;
  list *temp = 0;
	list *node = *l;
	while(node){
		temp = node->next;	
		node->next = previous;
		previous = node;
		node = temp;
	}
	*l = previous;
}

void recursiveReverse(list **l){
	list *first = *l;
	if(!first) return;
	
	list *rest = first->next;
	if(!rest) return;
	recursiveReverse(&rest);
	first->next->next = first;
	first->next = 0;

	*l = rest;
}
	

/*
int main()
{
	list *my_list = 0;

	insert(&my_list, 3);
	insert(&my_list, 4);
	insert(&my_list, 5);

	print_list(my_list);
	reverse(&my_list);
	print_list(my_list);
	recursiveReverse(&my_list);
	print_list(my_list);
}
*/
