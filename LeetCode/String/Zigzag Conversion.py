class Solution:
    def convert(self, s: str, numRows: int) -> str:
        if numRows <= 1 or len(s) <= numRows:
            return s
        rows = [[] for row in range(numRows)]
        row, temp, i, res = 0, 'D', 0, ""
        while i < len(s):
            rows[row] += s[i]
            if row == len(rows) - 1:
                temp = 'U'
            if row == 0:
                temp = 'D'
            row = row + 1 if temp == 'D' else row - 1
            i += 1
        for row in rows:
            for char in row:
                res += char
        return res
