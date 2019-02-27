#include <stdio.h>
void merge(int array[], int start, int mid, int end){
  int i, j, k;
  int n1 = mid - start + 1;
  int n2 = end - mid;
  int Left[n1], Right[n2]; //temporary arrays created
  for (i = 0; i < n1; i++)
    Left[i] = array[start + i]; //data copied to Left sub array
  for (i = 0; i < n2; i++)
    Right[i] = array[mid + 1 + i]; // data copied to right sub array

  //merging the sub arrays
  i = 0, j = 0; //initial index of left and right sub arrays
  k = start;
  while (i < n1 && j < n2){
    if (Left[i] <= Right[j]){
      array[k] = Left[i];
      i++;
    }
    else{
      array[k] = Right[j];
      j++;
    }
    k++;
  }
  //copying remaining elements of Left array
  while (i < n1){
    array[k] = Left[i];
    i++;
    k++;
  }
  //copying remaining elements of Right array
  while (j < n2){
    array[k] = Right[j];
    j++;
    k++;
  }
}
void mergeSort(int array[], int left, int right){
  if (left < right){
    int mid = (left + right) / 2;
    mergeSort(array, left, mid);
    mergeSort(array, mid + 1, right);
    merge(array, left, mid, right);
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
  //merge sort
  mergeSort(array, 0, 9);
  printf("Array after sorting\n");
  printArray(array, 10);
  return 1;
}

/*
  Output
    Initial Array
    12 11 13 5 6 7 98 56 26 9
    Array after sorting
    5 6 7 9 11 12 13 26 56 98
  Time Complexity for all the cases: nlog(n)
  Space Complexity for array of n size: 2n or O(n)
*/