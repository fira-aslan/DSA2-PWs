#include <stdio.h>

int main(){
  int numEl;
  int N;
  int temp;
  printf("Enter the number of elements in the array: ");
  scanf("%d", &numEl);
  int arr[numEl];
  printf("Enter the elements of the array: ");
  for(int i=0; i<numEl; i++){
    scanf("%d", &arr[i]);
  }
  printf("Enter the number of times to rotate: ");
  scanf("%d", &N);

  for(int i=0; i<N; i++){
    temp=arr[0];
    for(int j=0; j<numEl-1; j++){
      arr[j]=arr[j+1];
    }
    arr[numEl-1]=temp;
  }

  printf("Left rotated array:\n");
  for(int i=0; i<numEl; i++){
    printf("%d ", arr[i]);
  }
  printf("\n");

  return 0;
}