class Solution(object):
    def twoSum(self, numbers, target):
        mp = {}
        for i in range(len(numbers)):
            mp[numbers[i]] = i
        for i in range(len(numbers)):
            needed = target - numbers[i]
            if needed in mp and i != mp[needed]:
                return [i, mp[needed]]
        return [-1, -1]
