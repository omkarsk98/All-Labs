#include <stdio.h>
void heapify(int array[], int i, int size)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int temp;
  if (left < size && array[left] > array[largest])
    largest = left;
  if (right < size && array[right] > array[largest])
    largest = right;
  if (largest != i)
  {
    temp = array[i];
    array[i] = array[largest];
    array[largest] = temp;
    heapify(array, largest, size);
  }
}
void heapSort(int array[], int size)
{
  int i, temp;
  for (i = size / 2 - 1; i >= 0; i--)
    heapify(array, i, size);
  for (i = size - 1; i >= 0; i--)
  {
    //swap array[0] with array[i]
    temp = array[0];
    array[0] = array[i];
    array[i] = temp;
    heapify(array, 0, i);
  }
}
void printArray(int array[], int size)
{
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", array[i]);
  printf("\n");
}
int main()
{
  int array[10] = {12, 11, 11, 5, 6, 7, 98, 56, 26, 9};
  printf("Initial Array\n");
  printArray(array, 10);
  heapSort(array, 10);
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
  Complexity
    Best Case, Average Case, Worst Case: nlog(n)
*/