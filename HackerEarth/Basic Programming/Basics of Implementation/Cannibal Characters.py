def Minimum_Operations (n, s):
    uniques = list(set(list(s)))
    res = 0
    for i in uniques:
        res += s.count(i) >> 1
    return res

T = int(input())
for _ in range(T):
    n = int(input())
    s = input()

    out_ = Minimum_Operations(n, s)
    print(out_)
