# Solution 1
class Solution:
    def findLongestWord(self, s: str, d: List[str]) -> str:
        candidate = ''
        for w in d:
            if candidate != '' and (len(w) < len(candidate) or len(w) == len(candidate) and w > candidate):
                continue
            i = j = 0
            while i < len(s) and j < len(w):
                if s[i] == w[j]: j += 1
                i += 1
            if j == len(w): candidate = w
        return candidate
# Solution 2

class Solution:

    def findLongestWord(self, s: str, dictionary: List[str]) -> str:
        alpha = [0] * 26
        res = ["", 0]
        for i in s:
            alpha[ord(i) - ord('a')] += 1
        total = sum(alpha)
        for i in dictionary:
            temp = alpha.copy()
            for j in i:
                if temp[ord(j) - ord('a')] > 0:
                    temp[ord(j) - ord('a')] -= 1
            left = total - sum(temp)
            if res[1] == left:
                res[0] = sorted([res[0], i])[0]
            elif res[1] < left:
                res[0] = i
                res[1] = left
        return res[0]
