// Doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLS{
  char value;
  struct DoublyLS* prev;
  struct DoublyLS* next;
} DLS;

void DLS_add(DLS** list, int value);
void DLS_show(DLS* list);
void freeDLS(DLS *list);
int isPalindrome(DLS *left);

int main(){
  DLS* list = NULL;
  DLS_add(&list, 'r');
  DLS_add(&list, 'o');
  DLS_add(&list, 't');
  DLS_add(&list, 'a');
  DLS_add(&list, 't');
  DLS_add(&list, 'o');
  DLS_add(&list, 'r');
  int check = isPalindrome(list);
  if(check == 1){
    printf("It's palindrome.\n");
  }
  else if(check == 2){
    printf("It's empty.\n");
  }
  else if(check == 0){
    printf("It's not palindrome.\n");
  }

  freeDLS(list);
  return 0;
}

int isPalindrome(DLS *left){
  if(left == NULL){
    return 2;
  }
  DLS *right = left;
  while(right->next != NULL){
    right = right->next;
  }
  while(left != right){
    if(left->value != right->value)
      return 0;
    left = left->next;
    right = right->prev;
  }
  return 1;
}

void DLS_add(DLS** list, int value){
  DLS* newDLS = malloc(sizeof(DLS));
  DLS* temp;
  newDLS->value = value;
  newDLS->next = NULL;
  temp = *list;

  if(*list == NULL) {
    newDLS->prev = NULL;
    *list = newDLS;
    return;
  }

  while(temp->next != NULL)
    temp = temp->next;
    temp->next = newDLS;
    newDLS->prev = temp;
}

void DLS_show(DLS* list){
  DLS* last;
  while(list != NULL) {
    printf("%c", list->value);
    last = list;
    list = list->next;
    if(list!=NULL){
      printf(", ");
    }
  }
  printf("\n");
}

void freeDLS(DLS *list){
  DLS *temp;
  while(list!=NULL){
    temp = list;
    list = list->next;
    free(temp);
  }
}
