//Objective to Write a C program for Insertion Sort
//Omkar Kulkarni
//169105119
#include <stdio.h>
void InsertionSort(int array[], int length){
  /* 
  This Sort is like arranging playing cards

  1. start from 2nd element 
  2. mark element as key
  3. if number to the left of key is greater than key, shift that number right
  4. repeat step 3 till next number on the left is not greater than key
  5. insert key at that location
  6. repeat for the length of array
   */
  int i, key, j;
  for (j = 1; j < length; j++){
    key = array[j];
    i = j - 1;
    while (i > -1 && array[i] > key){
      array[i + 1] = array[i];
      i = i - 1;
    }
    array[i+1] = key;
  }
}
void main()
{
  int array[10] = {122 , 33, 64, 26, 42, 97, 36, 100, 2, 88}, i;
  printf("-------------------Before Sorting-------------------\n");
  for (i = 0; i < 10; i++)
    printf("%d ", array[i]);
  printf("\n");
  InsertionSort(array, 10);
  printf("-------------------Array in Sorted format-------------------\n");
  for (i = 0; i < 10; i++)
    printf("%d ", array[i]);
  printf("\n");
}

/* 
  Output-> 2 12 26 33 36 42 64 88 97 100
*/