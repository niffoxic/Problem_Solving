n, k = map(int, input().split())
val = list(input())
left, i = 0, 0
while left < k and i < n:
    if i == 0 and val[0] != '1':
        val[0] = '1'
        left += 1
    elif i > 0 and val[i] != '0':
        val[i] = '0'
        left += 1
    i += 1
if n == 1 and k:
    val = "0"
print("".join(val))
