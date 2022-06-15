#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define HASH_TABLE_SIZE 10

typedef struct Hash_Node {
  int key;
  struct Hash_Node* next;
  struct Hash_Node* prev;
} Node;


Node* hash_table[HASH_TABLE_SIZE];

int hash_function(int key);
void insertKey(int key);
bool findKey(int key);
bool removeKey(int key);
void print_hash_table();


int main(){
  int count = 10;
  int data[] = {450, 123, 678, 910, 815, 396, 673, 589, 928, 394};

  for (int i = 0; i < HASH_TABLE_SIZE; i++){
    hash_table[i] = malloc(sizeof(Node));
    hash_table[i]->next = NULL;
  }

  for (int i = 0; i < count; i++){
    insertKey(data[i]);
  }
  print_hash_table();

  if(findKey(678)){
    printf("The key=%d is in the hash table.\n", 678);
  }
  else{
    printf("The key=%d is not in the hash table.\n", 678);
  }

  if(removeKey(910)){
    printf("Removed the key=%d from the hash table.\n", 910);
  }

  print_hash_table();
  return 0;
}

int hash_function(int key){
  return (key % HASH_TABLE_SIZE);
}

void insertKey(int key){
  int index = hash_function(key);
  Node *node = (Node*) malloc(sizeof(Node));
  node->key = key;
  node->next = hash_table[index]->next;
  hash_table[index]->next = node;
}


bool findKey(int key){
  int index = hash_function(key);
  Node* node = hash_table[index]->next;
  while(node && node->key != key){
    node = node->next;
  }
  if(node){
    return true;
  }
  else{
    return false;
  }
}


bool removeKey(int key){
  int index = hash_function(key);
  Node* node = hash_table[index];
  while(node->next && node->next->key != key){
    node = node->next;
  }
  if(node->next){
    Node* target;
    target = node->next;
    node->next = target->next;
    free(target);
    return true;
  }
  else{
    return false;
  }
}


void print_hash_table(){
  printf("\nThe hash table contents:\n");
  for(int i = 0; i < HASH_TABLE_SIZE; i++){
    Node* node;
    printf("%d: ", i);
    node = hash_table[i]->next;
    while(node){
      printf("key=%d\t", node->key);
      node = node->next;
    }
    printf("\n");
  }
  printf("\n");
}



