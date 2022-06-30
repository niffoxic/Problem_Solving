import functools

n = int(input())
arr = list(map(int, input().split()))
res, prefix = [], [0]
for i in arr:
    prefix.append(prefix[-1] + i)

for i in range(n):
    left, right = i + 1, i + 1
    while right <= n:
        length = right - left + 1
        sub = prefix[right] - prefix[left - 1]
        left_over = prefix[n] - sub
        left_range = n - length
        if not left_range or sub / length > left_over / left_range:
            res.append([left, right])
        right += 1


def compare(x, y):
    if x[0] == y[0]:
        return x[1] > y[1]
    return x[0] < y[0]


res = sorted(res, key=functools.cmp_to_key(compare))
print(len(res))
for i in res:
    print(i[0], i[1])
