class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        return False if x < 0 or x != int(str(x)[::-1]) else True
        
