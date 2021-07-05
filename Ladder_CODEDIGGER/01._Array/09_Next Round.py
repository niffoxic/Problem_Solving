n, k = map(int, input().split())
tour = list(map(int, input().split()))
res = 0
for i in range(n):
    if tour[k - 1] <= tour[i] and tour[i] > 0:
        res += 1
print(res)
