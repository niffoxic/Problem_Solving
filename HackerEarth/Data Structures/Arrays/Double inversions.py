for _ in range(int(input())):
    n = int(input())
    left = list(map(int, input().split()))
    right = list(map(int, input().split()))
    right.reverse()
    res = [0] * n
    used = set()
    nope = False
    for i in range(n - 1, -1, -1):
        val = n - left[i]
        val -= right[i]
        if val in used or val <= 0:
            nope = True
            break
        used.add(val)
        res[i] = val
    if nope:
        print(-1)
    else:
        print(*res)
