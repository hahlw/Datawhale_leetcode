#
# @lc app=leetcode.cn id=217 lang=python3
#
# [217] 存在重复元素
#
class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        dic = dict()
        for num in nums:
            if num in dic:
                return True
            dic[num] = 1
        return False
      
            
        

