def high(x):
    res = ""
    counts = 0
    temp = 0
    current = ""
    for i in x:
        if i == ' ':
            if temp > counts:
                counts = temp
                res = current
            current = ""
            temp = 0
        else:
            temp += (ord(i) - ord('a')) + 1
            current += i
    if temp > counts:
        res = current
    return res


check = 'man i need a taxi up to ubud'
print(high(check))