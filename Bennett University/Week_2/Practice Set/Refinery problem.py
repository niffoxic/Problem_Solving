for _ in range(int(input())):
    e, m = map(int, input().split())
    ans = 0
    for i in range(1, m + 1):
        ans = max(ans, e % i)
    print(ans)
