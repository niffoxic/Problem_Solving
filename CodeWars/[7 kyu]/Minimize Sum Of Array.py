def min_sum(arr):
    arr.sort()
    i, j = 0, len(arr)
    res = 0
    while i < j:
        res += arr[i] * arr[j]
        i += 1
        j += 1
    return res if i == j else res + arr[i]
