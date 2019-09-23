#
# @lc app=leetcode.cn id=258 lang=python3
#
# [258] 各位相加
#
class Solution:
    def addDigits(self, num: int) -> int:
        # while num > 9:
        #     temp = str(num)
        #     lens  = len(temp)
        #     num = 0
        #     for i in range(lens):
        #         num += int(temp[i])
        # return num
        if num > 9 :
            return num%9 if num%9 else 9
        return num
        

