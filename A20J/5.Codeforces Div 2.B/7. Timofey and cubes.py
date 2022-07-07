n = int(input())
arr = list(map(int, input().split()))
last = True
left, right = 0, n - 1
while left < right:
    if last:
        arr[left], arr[right] = arr[right], arr[left]
        last = False
    else:
        last = True
    left += 1
    right -= 1
print(*arr)
