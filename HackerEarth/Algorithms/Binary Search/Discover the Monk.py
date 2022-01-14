number_two_integers = [int(x) for x in input().split()]
array_list = [int(x) for x in input().split()]
array_list = sorted(array_list)
 
def binary_iterative(arr, key):
    left = 0
    right = len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == key:
            return print("YES")
        elif arr[mid] < key:
            left = mid + 1
        elif arr[mid] > key:
            right = mid - 1
    return print("NO")
 
 
left = 0
right = len(array_list) - 1
 
for i in range(number_two_integers[1]):
    check = int(input())
    binary_iterative(array_list, check)
