#include <stdio.h>
#include <malloc.h>
#include <string.h>

struct tree_node{
  int data;
  struct tree_node *left;
  struct tree_node *right;

};

struct List {
  int data;
  struct List *next;
  struct List *prev;
};

typedef struct List* LIST;
typedef struct tree_node* NODE;

void print_infix(NODE tree);
void vsum(NODE tree);
void vsum_list(NODE tree, LIST node);
LIST create_node(int data, LIST next, LIST prev);
NODE destroyTree(NODE tree);
NODE insertNode(NODE tree, int data);
NODE newNode(int data, NODE left, NODE right);

/* Guidance taken from https://www.faceprep.in/c/find-the-vertical-sum-in-a-given-binary-search-tree/ */

int main(){
  int n;
  int x, i;
  char command[10];
  NODE tree = NULL;
  printf("Enter the number of data of the tree: ");
  scanf("%d", &n);
  printf("Input the tree data: ");
  for (i = 0; i < n; i++){
    scanf("%d", &x);
    tree = insertNode(tree, x);
  }
  printf("Vertical sum: ");
  vsum(tree);
  tree = destroyTree(tree);
  return 0;
}

NODE newNode(int data, NODE left, NODE right){
  NODE tree = (NODE) malloc(sizeof(struct tree_node));
  tree->data = data;
  tree->left = left;
  tree->right = right;
  return tree;
}


NODE insertNode(NODE tree, int data){
  if(tree == NULL){
    return newNode(data, NULL, NULL);
  }
  else if(data > tree->data){
    tree->right = insertNode(tree->right, data);
  }
  else if(data < tree->data){
    tree->left = insertNode(tree->left, data);
  }
  else{}
  return tree;
}


NODE destroyTree(NODE tree){
  if(tree != NULL){
    destroyTree(tree->left);
    destroyTree(tree->right);
    free(tree);
  }
  return NULL;
}


LIST create_node(int data, LIST next, LIST prev){
  LIST list = (LIST) malloc(sizeof(struct List));
  list->data = data;
  list->next = next;
  list->prev = prev;
  return list;
}



void vsum_list(NODE tree, LIST node){
  if(tree == NULL){
  return;
  }
  node->data += tree->data;
  if(tree->left){
    if(node->prev == NULL){
      node->prev = create_node(0, node, NULL);
    }

    vsum_list(tree->left, node->prev);
  }

  if(tree->right){
    if(node->next == NULL){
      node->next = create_node(0, NULL, node);
    }
    vsum_list(tree->right, node->next);
  }

}



void vsum(NODE tree){
  LIST c = NULL;
  LIST sums = create_node(0, NULL, NULL);
  vsum_list(tree, sums);
  while(sums->prev != NULL){
    sums = sums->prev;
  }
  while(sums != NULL){
    printf("%d ", sums->data);
    sums = sums->next;
  }
  printf("\n");

}


void print_infix(NODE tree){
  if(tree == NULL){
    return;
  }
  print_infix(tree->left);
  printf("%d ", tree->data);
  print_infix(tree->right);
}


