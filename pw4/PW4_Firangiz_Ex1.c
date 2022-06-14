#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedList{
  int val;
  struct LinkedList* next;
} LS;


void LS_add(LS **list, int val);
int FrontBackSplit(LS *list, LS **front, LS **back);
void LS_show(LS *list);

int main(){
  int n;
  LS *list = NULL;
  LS *front = NULL;
  LS *back = NULL;
  LS_add(&list, 1);
  LS_add(&list, 4);
  LS_add(&list, 3);
  LS_add(&list, 11);
  LS_add(&list, 8);
  switch(FrontBackSplit(list, &front, &back)) {
      case 0:
        printf("The main list is empty.\n");
        break;

      case 1:
        printf("Only one element in the main list.\nDisplaying the main list:\n");
        LS_show(list);
        break;

      case 2:
        printf("The main list:\n");
        LS_show(list);
        printf("The obtained front list:\n");
        LS_show(front);
        printf("The obtained back list:\n");
        LS_show(back);
        break;

      default:
        break;
  }

  free(list);
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

int FrontBackSplit(LS *list, LS **front, LS **back){
  int length = 0;
  if(list==NULL){
    return 0;
  }
  else{
    LS *temp = list;
    while(temp->next != NULL){
      temp = temp->next;
      length++;
    }
    length++;
    if(length==1){
      return 1;
    }
    else{
      int m = length/2;
      int n = 0;
      temp = list;
      if(length%2==0){
        while(temp!=NULL){
          while(n<m){
            LS_add(front, temp->val);
            temp = temp->next;
            n++;
          }
          LS_add(back, temp->val);
          temp = temp->next;
        }
      }
      else if(length%2!=0){
        while(temp!=NULL){
          while(n<=m){
            LS_add(front, temp->val);
            temp = temp->next;
            n++;
          }
          LS_add(back, temp->val);
          temp = temp->next;
        }
      }
      return 2;
    }
  }
}

void LS_show(LS* list){
  for(LS* l=list; l!=NULL; l=l->next){
    printf("%d ", l->val);
  }
  printf("\n");
}
