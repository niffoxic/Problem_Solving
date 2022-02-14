for _ in range(int(input())):
    n = int(input())
    temp = n
    res = 0
    while temp:
        res += 1
        temp = temp & (temp - 1)
    print(res)
    i = 0
    while n:
        if (n & 1):
            print(3**i, end=" ")
        n = n >> 1
        i += 1
    print()
