#include<stdio.h>

int i,l;
int search(int ,int *,int);

int main(){
  int n,m;

  // prompts to enter the number
  // of elements in the array
  scanf("%d",&n);

  // declares an array of integers
  // of size n after scanning to n
  int a[n];

  // then it fills the array with
  // the numbers entered from the terminal
  for(i=0;i<n;i++) {scanf("%d",&a[i]);}

  // prompts for the element to look for
  // in the array
  scanf("%d",&m);

  // searches for the element
  // and prints corresponding message
  search(n,a,m);
  return 0;
}

int search(int n,int *a,int m){
  // traverses the array a (from the arguments)
  // using the number of elements n (from the arguments)
  // and compares each element of the array with 
  // the value m (from the arguments)
  for(i=0;i<n;i++){
    if(m==a[i]){
      l=1;    // set l to 1 if value m is present in the array
      break; // exit the loop
    }
  }

  // check l, if it's 1 then element is present
  // print the corresponding message
  if(l==1){
    printf("%d is present in the array",m);
  }
  // otherwise, print that the element
  // is not present in the array
  else{
    printf("%d is not present in the array",m);
  }
}

// time complexity is O(n) and space complexity is O(1)