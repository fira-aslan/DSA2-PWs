// Doubly linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct DoublyLS{
  int value;
  struct DoublyLS* prev;
  struct DoublyLS* next;
} DLS;

void DLS_add(DLS** list, int value);
void DLS_show(DLS* list);
int min(DLS* list);
int max(DLS* list);
void freeDLS(DLS *list);

int main(){
  DLS* list = NULL;
  DLS_add(&list, 6);
  DLS_add(&list, 22);
  DLS_add(&list, 5);
  DLS_add(&list, 4);
  DLS_add(&list, 12);
  DLS_add(&list, 9);
  printf("The doubly linked list is:\n");
  DLS_show(list);
  printf("Minimum element in the list is %d\n", min(list));
  printf("Maximum element in the list is %d\n", max(list));
  freeDLS(list);
  return 0;
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
    printf("%d", list->value);
    last = list;
    list = list->next;
    if(list!=NULL){
      printf(", ");
    }
  }
  printf("\n");
}

int min(DLS* list){
  int min = list->value;
  DLS* temp = list;
  while(temp->next!=NULL){
    if(min>temp->next->value){
      min = temp->next->value;
    }
    temp = temp->next;
  }
  return min;
}

int max(DLS* list){
  int max = list->value;
  DLS* temp = list;
  while(temp->next!=NULL){
    if(max<temp->next->value){
      max = temp->next->value;
    }
    temp = temp->next;
  }
  return max;
}

void freeDLS(DLS *list){
  DLS *temp;
  while(list!=NULL){
    temp = list;
    list = list->next;
    free(temp);
  }
}

