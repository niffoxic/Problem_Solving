n = int(input())
m = (n // 2) + 1
print(m)
for i in range(1, m + 1):
    print(1, i)
left_over = n - m
val = 2
while left_over:
    print(val, m)
    val += 1
    left_over -= 1
