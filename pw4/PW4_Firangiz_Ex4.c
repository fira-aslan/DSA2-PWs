#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList{
	int val;
	struct LinkedList* next;
} LS;


void RemoveDuplicates(LS* list);
void LS_add(LS **list, int val);
void LS_show(LS *list);
void freeLS(LS *list);


int main(){
	LS* list = NULL;

	LS_add(&list, 4);
	LS_add(&list, 6);
	LS_add(&list, 10);
	LS_add(&list, 10);
	LS_add(&list, 12);
	LS_add(&list, 12);					

	printf("The original linked list is:\n");
	LS_show(list);

	RemoveDuplicates(list);
	printf("The linked list after removing duplicates is:\n");		
	LS_show(list);
  freeLS(list);
	return 0;
}

void RemoveDuplicates(LS* list){
	LS* node = list;
	LS* save_thenext;

	if(node == NULL)
	  return;

	while (node->next != NULL){
	  if (node->val == node->next->val){		
		  save_thenext = node->next->next;
		  free(node->next);
		  node->next = save_thenext;
	  }
	  else{
		  node = node->next;
  	}
	}
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