class Solution(object):
    def lengthOfLastWord(self, s):
        return len(s.lstrip().split()[-1])
