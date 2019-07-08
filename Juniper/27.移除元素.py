#
# @lc app=leetcode.cn id=27 lang=python3
#
# [27] 移除元素
#
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        i = 0
        lens = len(nums)
        while i < lens:
            if nums[i]== val:
                del nums[i]
                lens -=1 
            else :
                i +=1
        return lens
            

        

