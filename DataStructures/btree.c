#include "btree.h"
#include <iostream>
using namespace std;

int main(){
	btree *test;
	insert(&test, 5);
	insert(&test, 8);
	insert(&test, 2);
	insert(&test,6);
	insert(&test,4);
	insert(&test,1);
	insert(&test,9);



	cout << "INORDER" << endl;
	print_inorder(test);
	cout << endl << "POSTORDER" << endl;
	print_postorder(test);
	cout << endl << "INORDER" << endl;
	print_preorder(test);
}
