n = int(input())
l = list()
diff = 0
ans = 0
for i in range(n):
    a, b = map(int, input().split())
    if b - a > diff:
        ans = 1
        diff = b - a
if ans:
    print("Happy Alex")
else:
    print("Poor Alex")
