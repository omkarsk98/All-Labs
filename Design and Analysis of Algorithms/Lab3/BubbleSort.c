#include<stdio.h>
void BubbleSort(int array[], int size){
  int i,j,temp;
  for(i=0; i<size; i++){
    for(j=0; j<size-1; j++){
      if(array[j+1]<array[j]){
        temp = array[j];
        array[j] = array[j+1];
        array[j+1] = temp;
      }
    }
  }
}
void printArray(int array[], int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}
int main(){
  int array[10] = {12, 11, 13, 5, 6, 7, 98, 56, 26, 9};
  printf("Initial Array\n");
  printArray(array, 10);
  BubbleSort(array, 10);
  printf("Array after sorting\n");
  printArray(array, 10);
  return 1;
}
/*
  Output:
    Initial Array
    12 11 13 5 6 7 98 56 26 9
    Array after sorting
    5 6 7 9 11 12 13 26 56 98
  Time Complexity for all the cases:
    O(n^2)
  Space Complexity for an input of n size
    n
*/