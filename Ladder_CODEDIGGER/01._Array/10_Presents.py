
n = int(input())
s = input().split()
print(*[s.index(str(i + 1)) + 1 for i in range(n)])
