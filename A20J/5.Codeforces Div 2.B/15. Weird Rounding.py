n, k = input().split()
k = int(k)
print(len(n)-1 if n.count('0') < k else sum([len(p) for p in n.split('0')[-k:]]))
