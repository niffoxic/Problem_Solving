n, a, b = map(int, input().split())
pipe = list(map(int, input().split()))
point = pipe[0]
pipe.remove(point)
pipe.sort()
accumulated = sum(pipe) + point
blocked = 0
right = n - 2
while right >= 0:
    if (point * a // accumulated) >= b:
        break
    else:
        blocked += 1
        accumulated -= pipe[right]
    right -= 1
print(blocked)
