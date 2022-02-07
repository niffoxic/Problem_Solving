n, y = map(int, input().split())
arr = list(map(int, input().split()))
res = 0
for i in arr:
    res = max(res, y - i)
print(res if res > 0 else 0)
