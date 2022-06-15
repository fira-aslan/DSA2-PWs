#include <stdio.h>
#include <stdlib.h>

struct node{
  int num;
  struct node *next;
};

int create(struct node **ls);
int palin_check (struct node *ls, int count);
void freeLS(struct node *ls);

int main() {
  struct node *p = NULL;
  int result, count;
  printf("Enter data into the list\n");
  count = create(&p);
  result = palin_check(p, count);
  if (result == 1)
    printf("The linked list is a palindrome.\n");
  else
    printf("The linked list is not a palindrome.\n");
  freeLS(p);
  return 0;
}

int create(struct node **ls) {
  int count = 0; 
  int element;
  int option;
  struct node *temp;
  do{
    printf("Enter a number:\n");
    scanf("%d", &element);
    count++;
    temp = (struct node *) malloc(sizeof(struct node));
    temp->num = element;
    temp->next = *ls;
    *ls = temp;
    printf("Continue [1] or exit [0]? : ");
    scanf("%d", &option);
  } while(option!=0);

  return count;
}


int palin_check (struct node *ls, int count){
  int i = 0, j;
  struct node *front, *rear;
  while(i != count/2){
    front = rear = ls;
    for(j=0; j<i; j++){
      front = front->next;
    }
    for(j=0; j<count-(i+1); j++){
      rear = rear->next;
    }
    if(front->num != rear->num){
      return 0;
    }
    else{
      i++;
    }
  }
  return 1;
}

void freeLS(struct node *ls){
  struct node *temp;
  while(ls!=NULL){
    temp = ls;
    ls = ls->next;
    free(temp);
  }
}

