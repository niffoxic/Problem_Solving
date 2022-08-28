a, b = map(int, input().split())

if (b - a) >= 10:
    print(0)
else:
    res = 1
    for i in range(a + 1, b + 1):
        res = (res * (i % 10)) % 10
    print(res)
