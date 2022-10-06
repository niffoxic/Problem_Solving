class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        dp = [[False] * n for i in range(n)]
        for i in range(n):
            dp[i][i] = True
        res_val = 1
        res = s[-1]

        for left in range(n - 1, -1, -1):
            for right in range(left + 1, n):
                if s[left] == s[right]:
                    if right - left == 1 or dp[left + 1][right - 1]:
                        dp[left][right] = True
                        if res_val < right - left + 1:
                            res_val = right - left + 1
                            res = s[left: right + 1]
        return res
