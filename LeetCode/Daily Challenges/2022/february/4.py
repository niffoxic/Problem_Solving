class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        l, b, f = 0, 0, {}
        for i, v in enumerate(nums):
            b += 1 if v else -1
            c = i + 1 if not b else i - f.setdefault(b, i)
            l = max(l, c)
        return l
