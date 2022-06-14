#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
	int val;
	struct LinkedList* next;
} LS;

void LS_add(LS **list, int val);
void LS_show(LS *list);
void freeLS(LS *list);
void LS_reverse(LS** list);


int main(){
	LS* list = NULL;

	LS_add(&list, 6);
	LS_add(&list, 25);
	LS_add(&list, 35);
	LS_add(&list, 45);

	printf("The original linked list is:\n");
	LS_show(list);
	LS_reverse(&list);
	printf("The list after reversing is:\n");
	LS_show(list);

  freeLS(list);
	return 0;
}

void LS_reverse(LS** list){
	LS* previous = NULL;
  LS* following = NULL;
	LS* current = *list;

	while (current != NULL){
		following = current->next;
		current->next = previous;
		previous = current;
		current = following;
	}
	*list = previous;
}

void LS_add(LS **list, int val){
  LS *newNode = malloc(sizeof(LS));
  newNode->val = val;
  newNode->next = NULL;
  if(*list == NULL)
    *list = newNode;

  else{
    LS *lastNode = *list;
    while(lastNode->next != NULL){
      lastNode = lastNode->next;
    }
    lastNode->next = newNode;
  }
}


void LS_show(LS *list){
  for(LS* l=list; l!=NULL; l=l->next){
    printf("%d ", l->val);
  }
  printf("\n");
}

void freeLS(LS *list){
  LS *temp;
  while(list!=NULL){
    temp = list;
    list = list->next;
    free(temp);
  }
}



