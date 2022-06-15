#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Tree_Node{
  int data;
  struct Tree_Node* left;
  struct Tree_Node* right;
} Node;

Node* newnode(int data);
bool printAncestors(Node *root, int target);


int main(){
  Node *root = newnode(15);
  root->left	 = newnode(6);
  root->right	 = newnode(9);
  root->left->left = newnode(1);
  root->left->right = newnode(4);
  root->left->right->right = newnode(21);
  root->left->right->right->left = newnode(25);
  root->right->left = newnode(3);
  root->right->right = newnode(12);
  printf("All ancestors the node with data 25:\n");
  printAncestors(root, 25);
  printf("\n");

  return 0;
}


bool printAncestors(Node *root, int target){
  if(root == NULL)
     return false;

  if(root->data == target)
     return true;
 
  if(printAncestors(root->left, target) || printAncestors(root->right, target)){
    printf("%d ", root->data);
    return true;
  }
  
  return false;
}


Node* newnode(int data){
  Node* node = (Node*) malloc(sizeof(Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return(node);
}


