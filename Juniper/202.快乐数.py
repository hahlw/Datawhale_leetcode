#
# @lc app=leetcode.cn id=202 lang=python3
#
# [202] 快乐数
#
class Solution:
    def isHappy(self, n: int) -> bool:
        tt = {}
        while n != 1:
            if tt.get(n,0) == 1:
                return False
            else:
                tt[n] = 1
                n = sum([int(i)**2 for i in str(str(n))])
        return True

        

