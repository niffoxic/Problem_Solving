class Solution:
    def findNthDigit(self, n: int) -> int:
        range_= 1
        counts = 9
        while counts * range_ < n:
            n -= counts * range_
            range_ += 1
            counts *= 10
        
        left = 10 ** (range_ - 1)
        index, remainder = divmod(n, range_)
        if not remainder:
            return int(str(left + index - 1)[-1])
        return int(str(left + index)[remainder - 1])
        
