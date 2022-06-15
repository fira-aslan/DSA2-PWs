#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Tree_Node{
  int data;
  struct Tree_Node* left;
  struct Tree_Node* right;
} Node;


Node* newNode(int data);
int countNodes(Node* root);
bool isComplete(Node* root, int index, int number_nodes);
bool checkHeap(Node* root);
bool isHeap(Node* root);


int main(){
	Node* root = newNode(9);
	root->left = newNode(5);
	root->right = newNode(4);
	root->left->left = newNode(1);
	root->left->right = newNode(3);
	root->right->left = newNode(2);
	root->right->right = newNode(1);

	if(isHeap(root))
		printf("The given binary tree is a max heap.\n");
	else
		printf("Given binary tree is not a max Heap.\n");

	return 0;
}

Node* newNode(int data){
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->right = node->left = NULL;
	return node;
}

int countNodes(Node* root){
	if(root == NULL)
		return 0;
	return 1 + countNodes(root->left) + countNodes(root->right);
}


bool isComplete(Node* root, int index, int number_nodes){
	if(root == NULL)
		return true;

	if(index >= number_nodes)
		return false;

	return isComplete(root->left, 2 * index + 1, number_nodes) && isComplete(root->right, 2 * index + 2, number_nodes);
}


bool checkHeap(Node* root){
	if(root->left == NULL && root->right == NULL)
		return (true);

	if(root->right == NULL){
		return (root->data >= root->left->data);
	}
	else{
		if(root->data >= root->left->data && root->data >= root->right->data)
			return ((checkHeap(root->left)) && (checkHeap(root->right)));
		else
			return (false);
	}
}


bool isHeap(Node* root){
	unsigned int node_count = countNodes(root);
	unsigned int index = 0;
	if(isComplete(root, index, node_count) && checkHeap(root))
		return true;
	return false;
}



