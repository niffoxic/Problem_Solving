length = int(input())
array = list(map(int, input().split()))
counts = 0
sums = 0
 
for i in range(length):
    if array[i] >= 0:
        counts += 1
        sums += array[i]
 
if sums:
        print(sums, counts)
else:
        print(max(array), 1)
