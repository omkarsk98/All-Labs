//Objective: To find time complexity for best case, 
// worst case and average case for Iterative Binary Search
//Omkar Kulkarni
//169105119
//2nd August 2018
#include <stdio.h>
int BinarySearch(int array[], int length, int find)
{
	int start, end, mid;
	start = 0;
	end = length - 1;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (array[mid] == find)
			return mid;
		else if (find < array[mid])
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1; //not found
}
void main()
{
	int length, i, find, result;
	printf("Enter array length:");
	scanf("%d", &length);
	int array[length];
	printf("Enter array in sorted manner\n");
	for (i = 0; i < length; i++)
	{
		scanf("%d", &array[i]);
	}
	printf("Enter the element to be searched:");
	scanf("%d", &find);
	result = BinarySearch(array, length, find);
	if (result == -1)
	{
		printf("%d not found\n", find);
	}
	else
		printf("%d found at location no %d in the array\n", find, result + 1);
}
