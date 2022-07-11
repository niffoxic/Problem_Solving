def getMinDiff(self, arr, n, k):
    arr.sort()
    res, mn, mx = arr[n - 1] - arr[0], arr[0], arr[n - 1]
    for i in range(1, n):
        if arr[i] >= k:
            mn, mx = min(arr[0] + k, arr[i] - k), max(arr[i - 1] + k, arr[n - 1] - k)
            res = min(res, mx - mn)
    return res
