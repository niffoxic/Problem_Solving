n, k = map(int, input().split())
kinds = list(map(int, input().split()))
ids, current = 0, n % kinds[0]

for i in range(k):
    val = n % kinds[i]
    if val < current:
        current = val
        ids = i

print(ids + 1, n // (kinds[ids]))
