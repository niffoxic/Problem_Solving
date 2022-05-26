class Solution(object):
    def waysToSplitArray(self, nums):
        res = 0
        left, right, total_sum = 0, len(nums) - 1, sum(nums)
        left_sum = nums[left]
        right_sum = total_sum - left_sum

        while left < right:
            if left_sum >= right_sum:
                res += 1
            left += 1
            left_sum += nums[left]
            right_sum -= nums[left]
        return res
