def calculate(a, b, n):
    a %= n
    res = 1
    while b > 0:
        if b & 1:
            res = (res * a) % n
        a = (a * a) % n
        b >>= 1
    return res


# replace this with system input
for _ in range(int(input())):
    b = int(input())
    p = int(input())
    m = int(input())
    print(calculate(b, p, m))
