for t in range(int(input())):
    n = int(input())
    arr = list(map(int, input().split()))
    ans = 1
    arr.sort()
    for i in arr:
        if i <= 0:
            continue
        if i == ans:
            ans += 1
        else:
            break
    print(ans)
