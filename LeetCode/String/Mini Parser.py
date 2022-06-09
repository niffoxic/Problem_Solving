# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:

    def dfs(self, i, s):
        res = NestedInteger()
        while i < len(s):
            if s[i] == '[':
                y, i = self.dfs(i + 1, s)
                res.add(y)
            elif i < len(s) and s[i] == ']':
                i += 1
                return res, i
            elif i < len(s) and s[i] == ',':
                i += 1
            else:
                if i < len(s):
                    start = i
                    while s[i] != ',' and s[i] != ']':
                        i += 1
                    res.add(NestedInteger(int(s[start:i])))
        return res, i

    def deserialize(self, s: str) -> NestedInteger:
        if s[0] == '[':
            res, i = self.dfs(1, s)
            return res
        else:
            res = NestedInteger()
            res.setInteger(int(s))
            return res
