class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordsDict, res = set(wordDict), set()
        res.add("")
        for i in range(len(s)):
            for j in range(i + 1, len(s) + 1):
                if s[i:j] in wordsDict and s[:i] in res:
                    res.add(s[:j])
        return s in res
