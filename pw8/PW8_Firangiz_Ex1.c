#include <stdio.h>
#include <stdlib.h>

struct node {
	int key;
	struct node *left, *right;
};


struct node* newNode(int item);
void inorder(struct node* root);
struct node* insert(struct node* node, int key);
void inorderDesc(struct node* root);


int main(){
	struct node* root = insert(root, 60);
	insert(root, 40);
	insert(root, 30);
	insert(root, 50);
	insert(root, 80);
	insert(root, 70);
	insert(root, 90);

  printf("The BST in ascending order:\n");
	inorder(root);
  printf("\n");
  printf("The BST in descending order:\n");
  inorderDesc(root);


	return 0;
}


struct node* newNode(int item){
	struct node* temp	= (struct node*) malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}


void inorder(struct node* root){
	if (root != NULL) {
		inorder(root->left);
		printf("%d \n", root->key);
		inorder(root->right);
	}
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


void inorderDesc(struct node* root){
	if (root != NULL) {
		inorderDesc(root->right);
		printf("%d \n", root->key);
		inorderDesc(root->left);
	}
}
