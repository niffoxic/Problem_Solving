b = int(input())
g = int(input())
n = int(input())
val = 0
b = min(b, n)
g = min(g, n)
while (b + g) // n > 0:
    if b:
        b -= 1
    else:
        g -= 1
    val += 1
print(val)

# second solution
print(min(g, n) - (n - min(b, n)) + 1)
