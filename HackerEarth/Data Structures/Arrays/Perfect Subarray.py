import math


def valid(x):
    val = int(math.sqrt(x))
    return val * val == x and x > 0


n = int(input())
arr = list(map(int, input().split()))
prefix = [0]

for i in arr:
    prefix.append(prefix[-1] + i)

res = 0
ans = []
for i in range(0, n):
    right = i + 1
    while right <= n:
        current = prefix[right] - prefix[i]
        if valid(current):
            res += 1
        right += 1

print(res)
