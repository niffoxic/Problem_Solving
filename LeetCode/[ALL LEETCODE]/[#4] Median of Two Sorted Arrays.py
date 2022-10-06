class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        total_len = len(nums1) + len(nums2)
        if total_len & 1:
            return self.position(nums1, nums2, total_len // 2)
        else:
            return self.position(nums1, nums2, total_len // 2, another=True)

    def position(self, nums1, nums2, mid_at, another=False):
        left, right = 0, 0
        reached = 0
        res = []
        while left < len(nums1) and right < len(nums2):
            if nums1[left] <= nums2[right]:
                if reached == mid_at and not another:
                    return nums1[left]
                elif reached == mid_at - 1 or reached == mid_at:
                    res.append(float(nums1[left]))
                reached += 1
                left += 1
            else:
                if reached == mid_at and not another:
                    return nums2[right]
                elif reached == mid_at - 1 or reached == mid_at:
                    res.append(float(nums2[right]))
                reached += 1
                right += 1

        while left < len(nums1):
            if reached == mid_at and not another:
                return nums1[left]
            elif reached == mid_at - 1 or reached == mid_at:
                res.append(float(nums1[left]))
            reached += 1
            left += 1

        while right < len(nums2):
            if reached == mid_at and not another:
                return nums2[right]
            elif reached == mid_at - 1 or reached == mid_at:
                res.append(float(nums2[right]))
            reached += 1
            right += 1
        # print(res)
        # print(mid_at)
        return sum(res) / 2
