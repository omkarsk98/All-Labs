# Iterative Binary Search
# Omkar Kulkarni


def BinarySearch(array, length, find):
    start = 0
    end = length-1
    while start <= end:
        mid = int((start+end)/2)
        if array[mid] == find:
            return mid
        elif find < array[mid]:
            end = mid-1
        else:
            start = mid+1
    return -1



array = []
print("Enter Array in sorted manner:")
# For validation purpose, sort the list
array = list(map(int, input().split()))
array.sort()
find = int(input("Search for:"))
result = BinarySearch(array, len(array), find)
if result == -1:
    print(find, " not found")
else:
    print("%d found at location number %d or list index %d" %
            (find, result+1, result))
