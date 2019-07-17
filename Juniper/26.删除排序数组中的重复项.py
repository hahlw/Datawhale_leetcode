#
# @lc app=leetcode.cn id=26 lang=python3
#
# [26] 删除排序数组中的重复项
#
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        lens = len(nums)   
        if not lens:
            return 0
        j = 0     
        for i in range(1,lens):
            if not nums[i] == nums[j]:
                j +=1
                nums[j] = nums[i]
            
        return j+1

        

