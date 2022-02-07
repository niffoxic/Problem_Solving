class Solution(object):
    def findTheDifference(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        arr = [0] * 26
        index = 0
        for i in range(0, len(s)):
            arr[ord(s[i]) - ord('a')] += 1
            arr[ord(t[index]) - ord('a')] -= 1
            index += 1
        arr[ord(t[index + 1]) - ord('a')] -= 1
        for i in range(0, 26):
            if arr[i] != 0:
                return chr(i + ord('a'))
        return ""
