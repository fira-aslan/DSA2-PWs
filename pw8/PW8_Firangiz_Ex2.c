#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};


struct node* newNode(int item);
struct node* insert(struct node* node, int key);
int isBST(struct node* node);


int main(){
	struct node* root = insert(root, 60);
	insert(root, 40);
	insert(root, 30);
	insert(root, 50);
	insert(root, 80);
	insert(root, 70);
	insert(root, 90);

  if(isBST){
    printf("The given Binary tree is a Binary search Tree\n");
  }
  else{
    printf("The given Binary tree is not a Binary search Tree\n");
  }


	return 0;
}


struct node* newNode(int item){
	struct node* temp = (struct node*) malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}



struct node* insert(struct node* node, int key){
	if (node == NULL)
		return newNode(key);

	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}


int isBST(struct node* node){
  if (node == NULL)
	  return 1;

  if (node->left != NULL && node->left->key > node->key)
	  return 0;
	
  if (node->right != NULL && node->right->key < node->key)
	  return 0;

  if (!isBST(node->left) || !isBST(node->right))
	  return 0;
  
  return 1;
}

