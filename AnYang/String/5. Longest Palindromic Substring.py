# 2019-07-23 Tue

class Solution:
    def longestPalindrome(self, s: str) -> str:   
        ls = len(s)
        if ls < 2:
            return s
        for i in range(ls):
            for j in range(i+1):
                res = s[j:ls-i+j]
                                
                if res == res[::-1]:
                    return s[j:ls-i+j]