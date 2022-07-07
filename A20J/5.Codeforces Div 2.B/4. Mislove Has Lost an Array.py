n, l, r = map(int, input().split())
low, high = 0, 0
left, right = 0, 0
arr = []
while left < l:
    low += (1 << left)
    arr.append(low)
    left += 1
print(low + (n - left), end=" ")
arr = []
while right < r:
    high += (1 << right)
    arr.append(high)
    right += 1
print(high + ((1 << (r - 1)) * (n - right)))
