#
# @lc app=leetcode.cn id=55 lang=python3
#
# [55] 跳跃游戏
#
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        lens = len(nums)
        if lens == 1:
            return True
        elif not nums[0]:
            return False
        def find(num, length):
            for i in range(length-1):
                if num[i] >= length-1 - i :
                    while num[i-1] >=1 and i > 0:
                        i = i-1
                    if i ==0:
                        return True
                    return True and find(num[:i+1], i+1)
            return False
        return find(nums,lens)

        

