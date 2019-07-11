# 2019-07-10 Wed


""" 79.26% """
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i = 0
        boundary = nums[0]
        cur = i = 0
        for i in range(len(nums)):
            boundary = max(boundary, i + nums[i])
            if boundary >= len(nums)-1:
                return True
            if i >= boundary:
                return False
        return True


""" 57.63% 24.60% """
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        i = 0
        boundary = nums[0]
        cur = i = 0
        while i < len(nums):
            boundary = max(boundary, i + nums[i])
            if boundary >= len(nums)-1:
                return True
            if i >= boundary:
                return False
            i += 1
        return True