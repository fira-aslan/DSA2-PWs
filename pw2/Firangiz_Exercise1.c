#include <stdio.h>

void bubble_sort(int* items, int count);
void print_array(int* items, int count);

int main(){
  int m, n;
  printf("Enter the number of elements for the first array: ");
  scanf("%d", &m);
  printf("Enter the number of elements in the second array: ");
  scanf("%d", &n);
  
  int mPlusN[m+n];
  int N[n];
  int count=0;

  printf("Enter %d elements:\n", m);
  for(int i=0; i<m+n; i++){
    if(i%2==0 && count<(m+n)){
      scanf("%d", &mPlusN[i]);
    }
    else{
        mPlusN[i] = -10;
        count++;
    }
  } // user will enter elements in the ascending (sorted) order

  printf("Enter %d elements:\n", n);
  for(int i=0; i<n; i++){
    scanf("%d", &N[i]);
  }
  bubble_sort(N, n); // sorting because of the condition of the exercise

  printf("Two unmerged arrays:\n");
  print_array(N, n);
  print_array(mPlusN, m+n);

  for(int i=0; i<n; i++){
    for(int j=0; j<(m+n); j++){
      if(mPlusN[j]==-10){
        if(N[i]>mPlusN[j-1] && N[i]<mPlusN[j+1]){
          mPlusN[j] = N[i];
        }
      }
    }
  }

  print_array(mPlusN, m+n);

  return 0;
}

// sorting only for arrays entered by the user, not for merged array
void bubble_sort(int* items, int count){
  register int i;
  register int not_sorted;
  register char temp;

  not_sorted = 1;
  while (not_sorted){
    not_sorted = 0;
    for (i=1; i<count; i++){
      if (items[i] < items[i-1]){
        temp = items[i];
        items[i] = items[i-1];
        items[i-1] = temp;
        not_sorted = 1;
      }
    }
  }
}

void print_array(int* items, int count){
  for(int i=0; i<count; i++){
    printf("%d  ", items[i]);
  }
  printf("\n");
}
