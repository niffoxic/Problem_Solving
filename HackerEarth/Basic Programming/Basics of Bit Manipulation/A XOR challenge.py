length = int(input())
max_val = 0
a = 0
 
for i in range(1, length):
    a = i ^ length
    max_val = max(max_val, a * (length ^ a))
 
print(max_val)
