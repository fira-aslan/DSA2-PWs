#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASH_TABLE_SIZE 11

typedef struct Hash_Node {
  int key;
  char status; // 'e' - empty, 'd' - deleted, 'o' - occupied
} Node;

Node hash_table[HASH_TABLE_SIZE];


int hash_function(int key);
void insertKey(int key, int stride);
bool findKey(int key, int stride);
bool removeKey(int key, int stride);
void print_hash_table(void);


int main(){
  int count = 11;
  int data[] = {12, 44, 13, 88, 23, 94, 11, 39, 20, 16, 5};

  for (int i = 0; i < HASH_TABLE_SIZE; i++){
    hash_table[i].status = 'e';
  }
    
  for (int i = 0; i < count; i++){
    insertKey(data[i], 1);
  }
  print_hash_table();

  if(findKey(23, 1)){
    printf("The key=%d is in the hash table.\n", 23);
  }
  else{
    printf("The key=%d is not in the hash table.\n", 23);
  }

  if(removeKey(88, 1)){
    printf("Removed the key=%d from the hash table.\n", 88);
  }

  print_hash_table();

  return 0;
}

int hash_function(int key){
  return (2*key+5) % 11;
}

void insertKey(int key, int stride){
  int probe = 1;
  int index = hash_function(key);
  while(hash_table[index].status == 'o' && probe <= HASH_TABLE_SIZE){
    index = (index + stride) % HASH_TABLE_SIZE;
    probe++;
  }
  if(probe > HASH_TABLE_SIZE){
    printf("There's no more room to insert a key/keys.\n");
  }
  else{
    hash_table[index].key = key;
    hash_table[index].status = 'o';
  }
}

bool findKey(int key, int stride){
  int probe = 1;
  int index = hash_function(key);
  while(true){
    if(hash_table[index].key == key){
      return true;
    }
    if(hash_table[index].status == 'e'){
      return false;
    }
    if(probe > HASH_TABLE_SIZE){
      return false;
    }
    index = (index + stride) % HASH_TABLE_SIZE;
    probe++;
  }
}


bool removeKey(int key, int stride){
  int probe = 1;
  int index = hash_function(key);
  while(true){
    if(hash_table[index].key == key){
      hash_table[index].status = 'd';
      return true;
    }
    if(hash_table[index].status == 'e'){
      return false;
    }
    if(probe > HASH_TABLE_SIZE){
      return false;
    }
    index = (index + stride) % HASH_TABLE_SIZE;
    probe++;
  }
}


void print_hash_table(void){
  printf("\nThe hash table contents:\n");
  for(int i = 0; i < HASH_TABLE_SIZE; i++){
    if(hash_table[i].status == 'o'){
      printf("[%d]=%d\t", i, hash_table[i].key);
    }
    else{
      printf("[%d]=__\t", i);
    }
  }
  printf("\n\n");
}

