arr = [0] * 26
s = input()
for i in s:
    arr[ord(i) - ord('a')] += 1
for _ in range(int(input())):
    s = input()
    for i in s:
        if not arr[ord(i) - ord('a')]:
            print("No")
            break
    else:
        print("Yes"
