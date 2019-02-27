//Objective: To write a C program for Selection Sort
//Omkar Kulkarni
//169105119
#include<stdio.h>
void SelectionSort(int array[], int length){
  /* 
    Start from 1st element
    Find minimum element from all the ones ahead of this. 
    swap the minimum and the current element
    Repeat for the complete array with next index as the current element
  */
  int i,min,j,temp;
  for(i=0;i<length;i++){
    min = i;
    for(j=i+1;j<length;j++){
      if(array[j]<array[min])
        min = j;
    }
    if(min!=i){
      temp = array[i];
      array[i] = array[min];
      array[min] = temp;
    }
  }
}
void main(){
  int array[10] = {12, 33, 64, 26, 42, 97, 36, 100, 2, 88}, i;
  printf("-------------------Before Sorting-------------------\n");
  for (i = 0; i < 10; i++)
    printf("%d ", array[i]);
  printf("\n");
  SelectionSort(array, 10);
  printf("-------------------Array in Sorted format-------------------\n");
  for (i = 0; i < 10; i++)
    printf("%d ", array[i]);
  printf("\n");
}
//Output -> 2 12 26 33 36 42 64 88 97 100