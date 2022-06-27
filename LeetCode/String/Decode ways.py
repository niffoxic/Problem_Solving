class Solution:

    def solve(self, i, s, dp):
        if i == len(s): return 1
        if dp[i] != -1: return dp[i]
        left = 0
        if s[i] != '0':
            left = self.solve(i + 1, s, dp)
        right = 0
        if i < len(s) - 1 and int(s[i:i + 2]) <= 26 and s[i] != '0':
            right = self.solve(i + 2, s, dp)
        dp[i] = left + right
        return dp[i]

    def numDecodings(self, s: str) -> int:
        dp = [-1] * (len(s) + 1)
        return self.solve(0, s, dp)
