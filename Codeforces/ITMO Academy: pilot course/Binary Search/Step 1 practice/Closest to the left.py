def bin_search(arr, x, l):
    left = 0
    right = l - 1
    val = 0
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] > x:
            right = mid - 1
        else:
            left = mid + 1
            val = max(val, left)
    return val
 
 
n, k = map(int, input().split())
array = list(map(int, input().split()))
q = list(map(int, input().split()))
for i in range(k):
    print(bin_search(array, q[i], n))
