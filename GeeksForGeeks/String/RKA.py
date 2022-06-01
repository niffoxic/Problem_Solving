class Solution:

    def search(self, patt, s):
        n, m = len(s), len(patt)
        res = []
        h_val = 1
        key, prime = 256, 101
        for i in range(1, m):
            h_val = (key * h_val) % prime
        p, t = 0, 0
        for i in range(m):
            p = (p * key + ord(patt[i])) % prime
            t = (t * key + ord(s[i])) % q
        for i in range(n - m + 1):
            if p == t:
                for j in range(m):
                    if s[i + j] != patt[j]:
                        break
                else:
                    res.append(i)
            if i < n - m:
                t = ((key * (t - ord(s[i]) * h_val)) + ord(h_val[i + m])) % prime
                if t < 0:
                    t = t + prime
        return res
