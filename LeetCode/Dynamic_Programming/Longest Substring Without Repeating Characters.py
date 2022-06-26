class Solution(object):

    def move(self, s, i, j, c, temp):
        while j < i:
            temp.remove(s[j])
            if s[j] == c:
                return j + 1
            j += 1
        return i + 1

    def lengthOfLongestSubstring(self, s):
        i, j = 0, 0
        size = 0
        res = 0
        temp = set()
        while i < len(s):
            if s[i] in temp:
                j = self.move(s, i, j, s[i], temp)
                size = len(temp)
            temp.add(s[i])
            size += 1
            if size > res:
                res = size
            i += 1
        return res
