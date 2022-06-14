#include <stdio.h>
#include <string.h>

#define CAPACITY 100

typedef struct Stack
{
  char array[CAPACITY];
  int size;
} stack;

stack push(stack st, char c);
stack pop(stack st);
char top(stack st);
void print(stack st);

int main(int argc, char* argv[]){
  if(argc!=2){
    printf("The command should be <exec> \"<stringLiteral>\"\n");
    return 1;
  }
  char exp[CAPACITY];
  strcpy(exp, argv[1]);
  stack st; st.size = 0;
  for(int i=0; i<strlen(exp); i++){
    if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
      st = push(st, exp[i]);
    }
    if(exp[i]==')'){
      if(top(st) == '('){
        st=pop(st);
        continue;
      }
    }
    if(exp[i]=='}'){
      if(top(st) == '{'){
        st=pop(st);
        continue;
      }
    }
    if(exp[i]==']'){
      if(top(st) == '['){
        st=pop(st);
        continue;
      }
    }
  }

  if(st.size==0){
    printf("Balanced\n");
  }
  else{
    printf("Not Balanced\n");
  }
  
  return 0;

}

stack push(stack st, char c){
  if(st.size<CAPACITY){
    st.array[st.size] = c;
    st.size++;
      return st;
  }
  else{
    printf("The stack is full.\n");
  }
}

stack pop(stack st){
  if(st.size!=0){
    char c = st.array[st.size-1];
    st.array[st.size-1] = '\0';
    st.size--;
    return st;
  }
  else{
    printf("The stack is empty.\n");
  }
}

char top(stack st){
  if(st.size!=0){
    return st.array[st.size-1];
  }
  else{
    printf("The stack is empty.\n");
    return -1;
  }
}

void print(stack st){
  printf("The stack is: ");
  for(int i=0; i<st.size; i++){
    printf("%c ", st.array[i]);
  }
  printf("\n");
}