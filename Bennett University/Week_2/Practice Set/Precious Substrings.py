for _ in range(int(input())):
    n = input()
    counts = input().count('1')
    print((counts * (counts + 1)) >> 1)
