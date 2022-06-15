class Solution(object):
    def findAnagrams(self, s, p):
        n, m = len(s), len(p)
        res = []
        if n < m:
            return []
        left, right = [0] * 26, [0] * 26
        for i in range(m):
            left[ord(p[i]) - 97] += 1
            right[ord(s[i]) - 97] += 1
        if left == right:
            res.append(0)
        i, j = 1, m
        while j < n:
            right[ord(s[i - 1]) - 97] -= 1
            right[ord(s[j]) - 97] += 1
            if left == right:
                res.append(i)
            i += 1
            j += 1
        return res
