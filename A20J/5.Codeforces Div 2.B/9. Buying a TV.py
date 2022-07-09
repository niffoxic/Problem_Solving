import math
a, b, x, y = map(int, input().split())
val = math.gcd(x, y)
while val != 1:
    while x % val == 0 and y % val == 0:
        x //= val
        y //= val
    val = math.gcd(x, y)
print(min(a // x, b // y))
