#include <stdio.h>
#include <stdlib.h>

typedef struct Queue{
  int val;
  struct Queue *next;
} queue;

void display();
void enqueue(int val);
void dequeue();

queue *front = NULL;
queue *rear = NULL;

int main(){
  int op, n;
  do{
    printf("Available operations:\n1. Insert an element\n2. Remove an element\n3. Display\n4. Exit\n");
    printf("Which operation do you choose 1-4? : ");
    scanf("%d", &op);

    if(op==1){
      printf("Enter the number: ");
      scanf("%d", &n);
      enqueue(n);
    }
    if(op==2){
      dequeue();
    }
    if(op==3){
      display();
    }

  } while(op != 4);

  return 0;
}

void enqueue(int val){
  queue *ptr = malloc(sizeof(queue));
  ptr->val = val;
  ptr->next = NULL;
  if (rear == NULL){
    front = ptr;
    rear = ptr;
  }
  else{
    rear->next = ptr;
    rear = rear->next;
  }
}

void dequeue(){
  if (front == NULL){
    printf("The queue is empty.\n");
  }
  else{
    queue *temp = front;
    front = front->next;
    printf("Element %d is removed\n", temp->val);
    free(temp);
  }
}

void display(){
  queue *temp;
  temp = front;
  printf("The queue is:\n");
  while (temp != NULL){
    printf("%d  ", temp->val);
    temp = temp->next;
  }
  printf("\n");
}

