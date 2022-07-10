n = int(input())
if n <= 2:
    print("No")
else:
    print("Yes")
    val = (n // 2) + (n & 1)
    print(1, val)
    print(n - 1, end=" ")
    for i in range(1, n + 1):
        if i == val:
            continue
        print(i, end=" ")
