#
# @lc app=leetcode.cn id=41 lang=python3
#
# [41] 缺失的第一个正数
#
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        # nums.sort()
        # j = 1
        # lens = len(nums)
        # for i in range(lens):
        #     if nums[i] <=0:
        #         if i ==lens-1:
        #             return 1
        #         continue
        #     elif i ==0 or not nums[i] == nums[i-1]:
        #         if not j == nums[i]:
        #             return j
        #         else :
        #             j +=1
        # return j
        lens = len(nums)
        if 1 not in nums:
            return 1
        if lens == 1:
            return 2
        for i in range(lens):
            if nums[i] <= 0 or lens < nums[i]:
                nums[i] = 1
        for i in range(lens):
            a = abs(nums[i])          
            nums[a-1] = - abs(nums[a-1]) #标记
        print(nums)
        for i in range(0,lens):
            if nums[i] > 0 :
               return i+1                  
        return lens + 1
