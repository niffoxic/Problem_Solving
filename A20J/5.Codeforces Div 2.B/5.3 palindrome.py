n = int(input())
res, alt, act = "", 0, False
for i in range(n):
    if not act:
        alt += 1
        res += "a"
    else:
        alt += 1
        res += "b"
    if alt == 2:
        alt = 0
        act = not act
print(res)
