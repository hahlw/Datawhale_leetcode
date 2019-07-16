#
# @lc app=leetcode.cn id=80 lang=python3
#
# [80] 删除排序数组中的重复项 II
#
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        lens = len(nums)   
        if lens < 2:
            return lens
        j = 1     
        for i in range(2,lens):
            if  not nums[i] == nums[j-1]:
                j +=1
                nums[j] = nums[i]
        return j+1
        # 91.32 %
        # lens = len(nums)   
        # if not lens:
        #     return 0
        # j = 0     
        # cnt = 0
        # for i in range(1,lens):
        #     if  nums[i] == nums[j]:
        #         cnt +=1 
        #         if cnt == 1:
        #             j +=1 
        #             nums[j] = nums[i]
        #     else:
        #         cnt = 0
        #         j +=1
        #         nums[j] = nums[i]    
        # return j+1

        

