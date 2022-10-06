# yea I know T_T

class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        res = 0
        lst = 1
        vals = {'-': False, '+': False}
        act = False
        for i in s:
            if i.isalpha() or i == '.':
                break
            if act:
                if not i.isdigit():
                    break
                lst *= 10
            if i in vals:
                if vals[i] == True or act:
                    break
                vals[i] = True
                act = True
                if vals['+'] and vals['-']:
                    break
            if i.isdigit():
                res *= lst
                act = True
                res += ord(i) - ord('0')
                lst = 1
        if vals['-']:
            res = min((1 << 31), res)
        else:
            res = min((1 << 31) - 1, res)
        return res * -1 if vals['-'] else res


# solve = Solution()
# print(solve.myAtoi("            -4193 with no words"))
