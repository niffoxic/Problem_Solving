class Solution:
    def palindromePairs(self, words: List[str]) -> List[List[int]]:
        if not words: return [[]]
        lookup = {w: i for i,w in enumerate(words)}
        res = []
        for i, w in enumerate(words):
            for j in range(len(w)+1):
                pre, suf = w[:j], w[j:]
                if pre==pre[::-1] and suf[::-1]!=w and suf[::-1] in lookup:
                    res.append([lookup[suf[::-1]], i])
                if suf==suf[::-1] and pre[::-1]!=w and pre[::-1] in lookup and j!=len(w):
                    res.append([i, lookup[pre[::-1]]])
        return res
