#include <stdlib.h>
#include <stdio.h>
typedef struct btree btree;

struct btree{
	int data;
	btree *left;
	btree *right;
};

void insert(btree **root, int data){
	if(*root)
		if((*root)->data > data)
			insert(&((*root)->left),data);
		else
			insert(&((*root)->right),data);
	else
	{
		*root = (btree*)calloc(1,sizeof(btree));
		(*root)->data = data;
	}
}

void print_postorder(btree *root){
	if(root)
	{
		print_postorder(root->left);
		print_postorder(root->right);
		printf("%d\n",root->data);
	}
}

void print_preorder(btree *root){
	if(root)
	{
		printf("%d\n",root->data);
		print_preorder(root->left);
		print_preorder(root->right);
	}
}

void print_inorder(btree *root){
	if(root)
	{
		print_inorder(root->left);
		printf("%d\n",root->data);
		print_inorder(root->right);
	}
}




/*int main(){
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
}*/
