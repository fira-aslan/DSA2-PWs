#include <stdio.h>

int main(){
  int a[10];
  int i, n, sum=0;
  printf("\n\n Find the sum of all elements of array:\n");
  printf("--------------------------------------\n");
  printf("Input the number of elements to be stored in the array :");
  scanf("%d",&n);
  
  printf("Input %d elements in the array :\n",n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
  i=0;
  for(i=0; i<n; i++){
    sum=sum+a[i];
  }
  printf("Sum of all elements stored in the array is : %d\n\n", sum);
  return 0;
}

// time complexity for worst and best case is O(n) and space complexity is O(1)