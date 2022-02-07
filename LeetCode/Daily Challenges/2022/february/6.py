class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        j = 2
        for i in range(2, len(nums)):
            if nums[i] != nums[j - 2]:
                nums[j] = nums[i]
                j += 1
        return j
