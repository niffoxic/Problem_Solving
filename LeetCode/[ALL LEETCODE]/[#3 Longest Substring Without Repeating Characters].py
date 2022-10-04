class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if len(s) <= 1: return len(s)
        left, res = 0, 0
        mp = {}
        for i in range(len(s)):
            if s[i] in mp and mp[s[i]] >= left:
                res = max(res, i - left)
                left = mp[s[i]] + 1
            mp[s[i]] = i
        return max(res, len(s) - left)
