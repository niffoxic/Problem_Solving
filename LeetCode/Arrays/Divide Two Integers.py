class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        abdd = abs(divisor)
        divi = abs(dividend)
        if abdd == 1:
            res = divi
        unit = len(str(abdd))
        res = ""
        sub = 0
        i = 0
        while i < len(str(divi)):
            sub = int(str(sub) + str(divi)[i:i + unit])
            sub_divide_time = 0
            while sub >= abdd:
                sub -= abdd
                sub_divide_time += 1
            res += str(sub_divide_time)
            next_round = sub
            i += unit
        res = int(res)
        if divisor < 0 and dividend > 0 or divisor > 0 and dividend < 0:
            return max(-(res), -2 ** 31)
        return min(res, 2 ** 31 - 1)
