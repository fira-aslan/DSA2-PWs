#include <stdio.h>
#include <stdlib.h>


typedef struct Tree_Node{
  int data;
  struct Tree_Node* left;
  struct Tree_Node* right;
} Node;

void printPaths(Node* node, int path[], int length);
void printPath(int arr[], int length);
Node* newnode(int data);


int main(){
  int path[1000];
  Node *root = newnode(15);
  root->left	 = newnode(6);
  root->right	 = newnode(9);
  root->left->left = newnode(1);
  root->left->right = newnode(4);
  root->right->left = newnode(3);
  root->right->right = newnode(12);
  printf("All Root-to-Leaf paths in the binary tree:\n");
  printPaths(root, path, 0);

  return 0;
}

void printPaths(Node* node, int path[], int length){
  if (node==NULL)
	  return;

  path[length] = node->data;
  length++;

  if (node->left==NULL && node->right==NULL){
	  printPath(path, length);
  }
  else{
    printPaths(node->left, path, length);
    printPaths(node->right, path, length);
  }
}


void printPath(int arr[], int len){
  for(int i=0; i<len; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");
}


Node* newnode(int data){
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}


