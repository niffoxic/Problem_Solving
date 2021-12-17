from collections import Counter


class Solution:
    def frequencySort(self, s: str) -> str:
        freq = Counter(s)
        here = []
        for i in freq:
            here.append([freq[i], i])
        here.sort(reverse=True)
        res = ""
        for i in range(len(here)):
            res += (here[i][0] * here[i][1])
        return res
