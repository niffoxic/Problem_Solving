# x pow y % n <- efficient way

def calculate(a, b, n):
    a %= n
    res = 1
    while b > 0:
        if b & 1:
            res = (res * a) % n
        a = (a * a) % n
        b >>= 1
    return res


for _ in range(int(input())):
    x, y, z = map(int, input().split())
    print(calculate(x, y, z))
