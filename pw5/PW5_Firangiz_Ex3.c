// Circular linked list

#include <stdio.h>
#include <stdlib.h>

typedef struct CircularList{
	int value;
	struct CircularList* next;
} CLS;

CLS* CLS_add(CLS* list, int value);
void CLS_reverse(CLS** list);
void CLS_show(CLS* list);

int main(){
	CLS *list = NULL;
  list = CLS_add(list, 6);
  list = CLS_add(list, 9);
  list = CLS_add(list, 20);
  list = CLS_add(list, 35);
  list = CLS_add(list, 45);
  printf("The original circular linked list:\n");
  CLS_show(list);
  CLS_reverse(&list);
  printf("The circular linked list after reversing:\n");
  CLS_show(list);
  
	return 0;
}

CLS* CLS_add(CLS* list, int value){
  CLS* newNode = (CLS*) malloc(sizeof(CLS));
  newNode->value = value;
  if(list == NULL){
    list = newNode;
    newNode->next = list;
  }
  else{
    CLS *temp = list;
    while(temp->next != list){
      temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = list;
  }
  return list;
}


void CLS_reverse(CLS** list){
  CLS *previous, *current, *following;
  CLS *last;
  if(*list == NULL){
    printf("The list is empty.\n");
    return;
  }
  last = *list;
  previous = *list;
  current = (*list)->next;
  *list = (*list)->next;
  while (*list != last){
    *list = (*list)->next;
    current->next = previous;
    previous = current;
    current = *list;
  }
  current->next = previous;
  *list = previous; 
}

void CLS_show(CLS* list){
  CLS* temp;
  if (list == NULL) {
    printf("The list is empty.\n");
    return;
  }
  temp = list;
  do{
    printf("%d ", temp->value);
    temp = temp->next;
  } while(temp != list);
  printf("\n");
}



