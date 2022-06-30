n = int(1e6) + 1
arr = [0] * n
for _ in range(int(input())):
    left, right = map(int, input().split())
    arr[left] += 1
    arr[right + 1] -= 1
res = 0
for i in range(1, n):
    arr[i] += arr[i - 1]
    if not arr[i]:
        res += i
print(res)
