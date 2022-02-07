for t in range(int(input())):
    s = input()
    left, right = [0] * 256, [0] * 256
    i, j = 0, len(s) - 1
    while i < j:
        left[ord(s[i])] += 1
        right[ord(s[j])] += 1
        i += 1
        j -= 1
    if left == right:
        print("YES")
    else:
        print("NO")
