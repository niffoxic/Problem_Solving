class Solution:
    def longestWord(self, words: List[str]) -> str:
        left = [[] for i in range(30)]
        for word in words:
            left[len(word) - 1].append(word)
        right = set(left[0])
        for i in range(1, 30):
            current = set()
            for word in left[i]:
                if word[:-1] in right:
                    current.add(word)
            if len(current) == 0:
                break
            right = current
        res = ""
        for word in right:
            res = word if not res else min(res, word)
        return res
