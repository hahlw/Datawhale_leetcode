# 2019-07-04 Thu
# 28. Implement strStr()

class Solution:
    def strStr(self, haystack: str, needle: str) -> int:
        try:
            idx = haystack.index(needle)
        except:
            return -1
        else:
            return idx