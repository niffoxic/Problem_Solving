class Solution(object):
    def convert(self, s, n):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if n == 1: return s
        mask = [[] for i in range(n)]
        path = 0
        zig = False
        for i in s:
            mask[path].append(i)
            if not zig:
                if path == n - 1:
                    zig = True
                    path -= 1
                else: path += 1
            else:
                if path == 0:
                    zig = False
                    path += 1
                else: path -= 1
        res = ""
        for i in mask:
            res += ''.join(i)
        return res
