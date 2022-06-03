class Solution:
    def smallestWindow(self, s, patt):
        lp = {}
        for i in patt:
            lp[i] = 1 if i not in lp else lp[i] + 1
        res = ""
        window_size, counts, i, j = int(1e9), len(patt), 0, 0
        while j < len(s):
            if counts == 0:
                if window_size > j - i + 1:
                    window_size = j - i + 1
                    res = s[i:j + 1]
                if s[i] in lp:
                    lp[s[i]] += 1
                    if lp[s[i]] > 0:
                        counts += 1
                i += 1
                while i < len(s) and s[i] not in lp:
                    i += 1
            else:
                if s[j] in lp:
                    lp[s[j]] -= 1
                    if lp[s[j]] >= 0:
                        counts -= 1
            if counts != 0:
                j += 1

        return -1 if not len(res) else res
