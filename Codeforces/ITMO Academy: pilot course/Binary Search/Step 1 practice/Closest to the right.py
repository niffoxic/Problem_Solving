def bin_search(arr, x, l):
    left = 0
    right = l - 1
    val = l + 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == x:
            return mid + 1
        elif arr[mid] > x:
            val = min(val, mid + 1)
            right = mid - 1
        else:
            left = mid + 1
 
    return val
 
 
n, k = map(int, input().split())
array = list(map(int, input().split()))
q = list(map(int, input().split()))
for i in range(k):
    print(bin_search(array, q[i], n))
