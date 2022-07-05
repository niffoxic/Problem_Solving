_ = list(input())
f = input()
t = input()
s = {}
res = ""
for i in range(26):
    s[_[i]] = i
for i in t:
    res += f[s[i]] if i.islower() else str(f[s[i.lower()]]).upper() if i.isupper() else i
print(res)
