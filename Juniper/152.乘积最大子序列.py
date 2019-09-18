#
# @lc app=leetcode.cn id=152 lang=python3
#
# [152] 乘积最大子序列
#
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        lens = len(nums)
        if not lens :
            return 
        res = temp = nums[0]
        for i in range(1,lens):            
            if temp :
                temp *= nums[i]
            else :
                temp = nums[i] 
            res =  max(nums[i],res,temp)  
        temp = nums[-1] 
        for i in range(1,lens-1):
            if temp :
                temp *= nums[-i-1]
            else :
                temp = nums[-i-1]                
            res =  max(nums[-i-1],res,temp)   
            
        return res 

        

