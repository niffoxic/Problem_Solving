class Solution:
    def convert(self, s: str, nr: int) -> str:
        if nr == 1:
            return s
        vec = [[] for i in range(nr)]
        val = 0
        act = False
        for i in s:
            vec[val].append(i)
            if not act:
                if val == nr - 1:
                    act = not act
                    val -= 1
                else:
                    val += 1
            else:
                if val == 0:
                    act = not act
                    val += 1
                else:
                    val -= 1

        res = ""
        for i in vec:
            res += ''.join(i)

        return res
