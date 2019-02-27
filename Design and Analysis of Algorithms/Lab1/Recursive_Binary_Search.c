//Objective: To find time complexity for best case, worst case and average case in Recursive Binary Search
//Omkar Kulkarni
//169105119
//2nd August 2018

#include<stdio.h>
int BinarySearch(int array[], int low, int high, int find){
	int mid;
	if(low > high){
		return -1;
	}
		
	mid = (low + high)/2;
	//printf("%d \n",mid);
	if(find == array[mid])
		return mid;
	else if(find < array[mid])
		return BinarySearch(array, low, mid-1, find);
	else
		return BinarySearch(array, mid+1, high, find);
}
main(){
	int length, i, find, result;
	printf("Enter array length:");
	scanf("%d",&length);
	int array[length];
	printf("Enter array in sorted manner\n");
	for( i = 0; i<length; i++ ){
		scanf("%d",&array[i]);
	}
	printf("Enter the element to be searched:");
	scanf("%d",&find);
	result = BinarySearch(array, 0, length-1, find);
	if(result==-1){
		printf("%d not found",find);
		//return;
	}	
	else
		printf("%d found at location no %d in the array", find, result+1);
		//return 1;
}
