#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left, *right;
};

struct node* newNode(int data);
int sumLeft(struct node *root);
int sumRight(struct node *root);

int main(){
	struct node *root = newNode(24);
	root->left = newNode(12);
	root->right = newNode(28);
	root->left->left = newNode(4);
	root->left->right = newNode(16);
  root->right->left = newNode(25);
	root->right->right = newNode(32);
	
	int sumL = sumLeft(root);
	printf("The sum of the left subtree: %d\n", sumL);
	int sumR = sumRight(root);
	printf("the sum of the right subtree: %d\n", sumR);

	return 0;
}

int sum(struct node *root) { 
   if(root == NULL) 
     return 0; 
   return sum(root->left) + root->data + sum(root->right); 
} 


int sumLeft(struct node *root){
	if(root == NULL)
		return 0;
	return sum(root->left); 
}


int sumRight(struct node *root){
	if(root == NULL)
		return 0;
	return sum(root->right);
}


struct node* newNode(int data){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

