#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
  int val;
  struct LinkedList* next;
} LS;


void LS_add(LS **list, int val);
void FrontBackSplit(LS *list, LS **front, LS **back);
void LS_show(LS *list);
void freeLS(LS *list);
int LS_length(LS *list);
LS* SortedMerge(LS *front, LS *back);
void MergeSort(LS** list);


int main(){
  int n;
  LS *list = NULL;
  LS_add(&list, 1);
  LS_add(&list, 4);
  LS_add(&list, 3);
  LS_add(&list, 11);
  LS_add(&list, 8);
  printf("The list is:\n");
  LS_show(list);
  MergeSort(&list);
  printf("The sorted list is:\n");
  LS_show(list);

  freeLS(list);
  return 0;
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

void FrontBackSplit(LS *list, LS **front, LS **back){
  LS *fast;
  LS *slow;
  slow = list;
  fast = list->next;
  while (fast != NULL){
    fast = fast->next;
    if (fast != NULL){
      slow = slow->next;
      fast = fast->next;
    }
  }
  *front = list;
  *back = slow->next;
  slow->next = NULL;
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

int LS_length(LS *list){
  int length = 0;
  if(list==NULL){
    return 0;
  }
  LS *temp = list;
  while(temp->next != NULL){
    temp = temp->next;
    length++;
  }
  length++;
  return length;
}


LS* SortedMerge(LS *front, LS *back){
  LS *newLS = NULL;
  if(front == NULL){
    newLS = back;
    return newLS;
  }
  else if(back == NULL){
    newLS = front;
    return newLS;
  }
  
  if (front->val <= back->val){
    newLS = front;
    newLS->next = SortedMerge(front->next, back);
  }
  else{
    newLS = back;
    newLS->next = SortedMerge(front, back->next);
  }
  return newLS;
}


void MergeSort(LS** list){
  LS* alist= *list;
  LS* front;
  LS* back;
  if((alist == NULL) || (alist->next == NULL)){
    return;
  }
  FrontBackSplit(alist, &front, &back);
  MergeSort(&front);
  MergeSort(&back);
  *list = SortedMerge(front, back);
}
