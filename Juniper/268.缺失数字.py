#
# @lc app=leetcode.cn id=268 lang=python3
#
# [268] 缺失数字
#
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        lens = len(nums)
       
        res = (lens+(lens+1) % 2)*((lens+1)//2)       
        temp = 0
        for i in range(lens):
            temp += nums[i]
        return res-temp
        

