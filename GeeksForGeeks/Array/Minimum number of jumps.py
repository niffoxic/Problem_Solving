class Solution:
    def minJumps(self, arr, n):
        mx, current, res = 0, 0, 0
        for i in range(0, n - 1):
            mx = max(mx, i + arr[i])
            if i == current:
                current = mx
                res += 1
            if mx >= n - i:
                return res
        return res
