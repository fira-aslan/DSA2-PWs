#include <stdio.h>
#include <stdlib.h>

// QuickSort function to sort an array in descending order
void QuickSort(int* a, int left, int right){
  int i = left;
  int j = right;
  int temp = a[i];
  if( left < right){
    while(i < j){
      while(a[j] <= temp && i < j){
        j--;
      }
      a[i] = a[j];
      while(a[i] >= temp && i < j){
        i++;
      }
      a[j] = a[i];
    }
    a[i] = temp;  
    QuickSort(a, left, i - 1);
    QuickSort(a, j + 1, right);
  }
}

int main(){
  int i;
  int a[8] = {20, 3, 45, 200, 22, 13, 120, 95};
  QuickSort(a, 0, 7);
  for(i=0; i<8; i++) printf("%d, ", a[i]);
  printf("\n");
  return 0;
}
