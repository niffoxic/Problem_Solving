class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left, right = 0, sum(nums)
        for i in range(len(nums)):
            if left == right - nums[i]:
                return i
            left += nums[i]
            right -= nums[i]
        return -1
