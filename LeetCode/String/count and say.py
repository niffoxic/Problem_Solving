class Solution:
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        temp = self.countAndSay(n - 1)
        res = []
        i = 0
        while i < len(temp):
            j = i
            while j + 1 < len(temp) and temp[j + 1] == temp[i]:
                j += 1
            count = str(j - i + 1)
            res.append(count)
            res.append(temp[i])
            i = j + 1
        return "".join(res)
