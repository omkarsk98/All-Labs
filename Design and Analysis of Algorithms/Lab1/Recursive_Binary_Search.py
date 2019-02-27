def BinarySearch(array, low, high, find):
    if low > high:
        return -1
    mid = int((low + high)/2)
    if find == array[mid]:
        return mid
    elif find < array[mid]:
        return BinarySearch(array, low, mid-1, find)
    else:
        return BinarySearch(array, mid+1, high, find)


array = []
array = list(map(int, input('Enter numbers in sorted manner:').split()))
array.sort()
find = int(input("Search for:"))
result = BinarySearch(array, 0, len(array)-1, find)
if result == -1:
    print(find, "not found")
else:
    print(find, "found at location number",
          result+1, "or list index", result)
