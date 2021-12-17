# op python 5 sec solution
class Solution:
    def trimMean(self, arr: List[int]) -> float:
        arr.sort()
        five = int((len(arr) * 5) / 100)
        return sum(arr[five:-five]) / len(arr[five:-five])
