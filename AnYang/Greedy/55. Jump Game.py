# 2019-07-11 Thu

""" 97.73% """
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        if len(nums)==1 or (0 not in nums): return True
        i = 0
        boundary = nums[0]
        cur = i = 0
        for i in range(len(nums)):
            t = i+ nums[i]
            if boundary < t:
                boundary = t
                continue
            if boundary >= len(nums)-1:
                return True
            if i >= boundary:
                return False
        return True


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