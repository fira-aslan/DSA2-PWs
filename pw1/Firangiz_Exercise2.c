#include <stdio.h>

void sortEvenOdd(int array[], int n);

int main(){
  int array[10];
  int i,j=0,k=0,n;
  printf("\n\n Separate odd and even integers in array:\n");
  printf("------------------------------------------------------\n");
  printf("Input the number of elements to be stored in the array :");
  scanf("%d",&n);

  printf("Input %d elements in the array :\n",n);
  for(i=0;i<n;i++){
    printf("element - %d : ",i);
    scanf("%d",&array[i]);
  }

  sortEvenOdd(array, n);

  // printing the reordered array
  printf("Array with even elements first, and then the odd elements:\n");
  for(int i = 0; i < n; i++){
    printf("%d ", array[i]);
  }

  puts("");
  return 0;
}

void sortEvenOdd(int array[], int n){
  for (int j = 0; j < n - 1; ++j) {
    for (int i = 0; i < n - j - 1; ++i) {
      if (array[i]%2!=0 && array[i + 1]%2==0) {
        // swapping happens if elements are not in the intended order
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

// time complexity is O(n^2) and space complexity is O(1)