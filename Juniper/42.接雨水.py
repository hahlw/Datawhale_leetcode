#
# @lc app=leetcode.cn id=42 lang=python3
#
# [42] 接雨水
#
class Solution:
    def trap(self, height: List[int]) -> int:
        85.7 %
        lens = len(height)
        right = lens-1
        res = left = right_max = left_max = 0
        while left < right:
            if height[left] < height[right]:
                left_max = max(height[left], left_max)
                res += left_max - height[left]
                left +=1
            else:
                right_max = max(height[right], right_max)
                res += right_max - height[right]
                right -=1
        return res 
      







        

