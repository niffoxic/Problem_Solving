lst = b = c = []
x = y = 0
for i in range(0, 2):
    string = input().lower()
    for j in range(0, len(string)):
        lst.append(string[j])
        b = lst[:len(lst) // 2]
        c = lst[len(lst) // 2:]
 
if (b != c):
    for i in range(0, len(b)):
        if ord(b[i]) < ord(c[i]):
            print("-1")
            break
        if ord(b[i]) > ord(c[i]):
            print("1")
            break
else:
    print("0")
