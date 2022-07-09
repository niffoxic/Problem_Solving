for _ in range(int(input())):
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    val = sum(a) + sum(b)
    if not val:
        print(0)
    if val == 2 or val == 3 or val == 1:
        print(1)
    if val == 4:
        print(2)
