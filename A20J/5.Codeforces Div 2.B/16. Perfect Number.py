def get(x):
    val = 0
    while x:
        val += x % 10
        x //= 10
    return val


n = int(input())
val = 19
while n:
    if get(val) == 10:
        n -= 1
    if not n:
        break
    val += 9

print(val)
