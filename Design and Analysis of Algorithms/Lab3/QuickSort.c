#include<stdio.h>
int Partition(int array[], int low, int high){
  int pivot = array[high];
  int i = (low - 1);
  int j, temp;
  for (j = low; j <= high - 1; j++){
    if (array[j] <= pivot){
      i++;
      //swap array[i] and array[j]
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
    }
  }
  //swap array[i+1] and array[high]
  temp = array[i + 1];
  array[i + 1] = array[high];
  array[high] = temp;
  return (i + 1);
}
void QuickSort(int array[], int low, int high){
  int part;
  if (low < high)
  {
    part = Partition(array, low, high);
    QuickSort(array, low, part - 1);
    QuickSort(array, part + 1, high);
  }
}
void PrintArray(int array[], int size){
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}
int main(){
  int array[10] = {12, 11, 13, 5, 6, 7, 98, 56, 26, 9};
  printf("Array before sorting\n");
  PrintArray(array, 10);
  QuickSort(array, 0, 9);
  printf("Array after sorting\n");
  PrintArray(array, 10);
}
/*
  Output:
    Array before sorting
    12 11 13 5 6 7 98 56 26 9
    Array after sorting
    5 6 7 9 11 12 13 26 56 98
  Time Complexity for n inputs
    Best Case: 
      nlog(n)
    Average Case:
      nlog(n)
    Worst Case:
      n^2
  Space Complexity for n inputs:
    log(n)
*/