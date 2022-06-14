#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
  int val;
  struct Stack *next;
} stack;

void push(stack** st, int val);
int pop(stack **st);
void display(stack *st);
void freeStack(stack *st);
int peek(stack *st);
int isEmpty(stack *st);

int main(int argc, char* argv[]){
  stack *original = NULL;
  stack *temp = NULL;
  int *poppedOrig = (int*) malloc(sizeof(int));
  int *poppedTemp = (int*) malloc(sizeof(int));
  push(&original, 67);
  push(&original, 91);
  push(&original, 101);
  push(&original, 25);
  display(original);
  while(!(isEmpty(original))){
    int top = pop(&original);
    while(!(isEmpty(temp)) && peek(temp)>top){
      int sort = pop(&temp);
      push(&original, sort);
    }
    push(&temp, top);
  }
  printf("After sorting\n");
  display(temp);
  freeStack(original);
  free(poppedOrig);
  return 0;
}

void push(stack** st, int val){
  stack* new_node = (stack*)malloc(sizeof(stack));
  stack* last = *st;
  new_node->val = val;
  new_node->next = NULL;
  if(*st == NULL){
    *st = new_node;
    return;
  }
  while (last->next != NULL) last = last->next;
  last->next = new_node;
  return;
}


int pop(stack **st){
  if(*st==NULL){
    return 0;
  }
  stack* last = *st;
  stack* secondLast = *st;
  while (last->next != NULL){
    secondLast = last;
    last=last->next;
  }
  if(last==*st){
    *st=NULL;
  }
  else{
    secondLast->next=NULL;
  }
  int top = last->val;
  free(last);
  return top;
}


void display(stack* st) {
  printf("The stack is:\n");
  while(st != NULL){
    if(st->next!=NULL){
      printf("%d, ", st->val);
    }
    else{
      printf("%d\n", st->val);
    }
    st = st->next;
  }
  
}

int peek(stack *st){
  if(st==NULL){
    return 0;
  }
  stack *last = st;
  while(last->next != NULL){
    last=last->next;
  }
  return last->val;
}

int isEmpty(stack *st){
  if(st==NULL){
    return 1;
  }
  return 0;
}


void freeStack(stack *st){
  stack *temp;
  while(st!=NULL){
    temp = st;
    st = st->next;
    free(temp);
  }
}