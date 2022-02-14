for _ in range(int(input())):
    x, y = map(int, input().split())
    if x < y or x < 0 or y < 0:
        print(-1)
    elif x >= y and y >= 0 and x >= 0:
        print(x)
