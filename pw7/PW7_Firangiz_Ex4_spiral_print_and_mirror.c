#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct node {
	int data;
	struct node* left;
	struct node* right;
};

void printSpiral(struct node* root);
void printGivenLevel(struct node* root, int level, int ltr);
int height(struct node* node);
struct node* newNode(int data);
void mirror(struct node* root);


int main() {
  struct node* root = newNode(1);
  root->left = newNode(2);
  root->right = newNode(3);
  root->left->left = newNode(4);
  root->left->right = newNode(5);
  root->right->left = newNode(6);
  root->right->right = newNode(7);
  root->right->right->right = newNode(9);
  root->left->right->left = newNode(8);
  printf("The Spiral Order traversal of binary tree is:\n");
  printSpiral(root);
  printf("\n");
  printf("The mirrored binary tree is:\n");
  mirror(root);
  printSpiral(root);
  printf("\n");
  return 0;
}


// Function to print spiral traversal of a tree
void printSpiral(struct node* root){
	int h = height(root);
	int i;
	bool ltr = false;
	for (i = 1; i <= h; i++) {
		printGivenLevel(root, i, ltr);
		ltr = !ltr;
	}
}

// Print nodes at a given level
void printGivenLevel(struct node* root, int level, int ltr){
	if (root == NULL)
		return;
	if (level == 1)
		printf("%d ", root->data);
	else if (level > 1){
		if (ltr){
			printGivenLevel(root->left, level - 1, ltr);
			printGivenLevel(root->right, level - 1, ltr);
		}
		else{
			printGivenLevel(root->right, level - 1, ltr);
			printGivenLevel(root->left, level - 1, ltr);
		}
	}
}


int height(struct node* node){
	if (node == NULL)
		return 0;
	else {
		int lheight = height(node->left);
		int rheight = height(node->right);

		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}


struct node* newNode(int data){
	struct node* node = (struct node*)
		malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}


void mirror(struct node* root){
  if (root==NULL)
    return; 
  else{
    struct node* temp;
     
    mirror(root->left);
    mirror(root->right);
 
    temp = root->left;
    root->left = root->right;
    root->right = temp;
  }
}
