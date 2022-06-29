n = int(input())
arr = sorted(list(map(int, input().split())))
res = 0
i = 0
while i < n - 1:
    counts, equals = 1, 1
    while (i < n - 1) and (arr[i + 1] - arr[i] <= 1):
        counts += 1
        if arr[i] == arr[i + 1]:
            equals += 1
        i += 1
    if counts > 1 and counts != equals:
        res += (counts * (counts - 1)) // 2
    i += 1
print(res)
