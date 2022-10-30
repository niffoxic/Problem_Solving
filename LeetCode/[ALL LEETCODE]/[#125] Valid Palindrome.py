class Solution:
    def isPalindrome(self, s: str) -> bool:
        string = ""
        for i in s:
            if i.isalpha() or i.isdigit():
                string += i.lower()
        return string[::-1] == string
        
