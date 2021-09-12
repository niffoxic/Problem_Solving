class Solution:
    def sortSentence(self, s: str) -> str:
        sem = s.split()
        res = [""] * 10
        for i in sem:
            index = int(i[-1])
            res[index] = i[:-1]
        return " ".join(res).strip()
