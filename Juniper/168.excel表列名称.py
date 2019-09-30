#
# @lc app=leetcode.cn id=168 lang=python3
#
# [168] Excel表列名称
#

# @lc code=start
import string
class Solution:
    def convertToTitle(self, n: int) -> str:
        # letter_list = string.ascii_uppercase
        s = ''
        while n:
            temp = n%26 
            n = n//26 
            if temp ==0:
                s = 'Z' + s
                n -= 1
            else:
                s = chr(64+temp) + s
        return s
# @lc code=end

