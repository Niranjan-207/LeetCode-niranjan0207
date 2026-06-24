class Solution:
    def isPalindrome(self, x: int) -> bool:
        s=str(x)
        temp=s[::-1]
        return s==temp