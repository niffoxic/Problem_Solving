for _ in range(int(input())):
    n, p, q, r = map(int, input().split())
    res = 0
    for i in range(1, n + 1):
        if not i % p and i % q and i % r:
            res += 1
        elif not i % q and i % p and i % r:
            res += 1
        elif not i % r and i % q and i % p:
            res += 1
    print(res)
