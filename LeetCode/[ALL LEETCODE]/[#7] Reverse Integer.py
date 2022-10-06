class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        neg = 0 if x > 0 else 1
        if neg: x *= -1
        res = 0
        mx_val = (1 << 31)
        while x > 0:
            res *= 10
            res = res + (x % 10)
            x //= 10
        if res > mx_val - 1 or res < -mx_val: return 0
        return res * -1 if neg else res
