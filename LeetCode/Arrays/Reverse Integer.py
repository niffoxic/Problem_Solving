class Solution:
    def reverse(self, x: int) -> int:
        num = abs(x)
        res = int(str(num)[::-1])
        if res < 2 ** 31 and res != 2 ** 31 - 1:
            if x < 0:
                return res * -1
            else:
                return res
        else:
            return 0
