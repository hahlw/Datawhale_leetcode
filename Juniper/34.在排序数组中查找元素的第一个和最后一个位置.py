#
# @lc app=leetcode.cn id=34 lang=python3
#
# [34] 在排序数组中查找元素的第一个和最后一个位置
#
class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if not nums :
            return [-1,-1]
        lens = len(nums)
        if lens == 1 and nums[0] == target:
            return [0,0]
        low, high = 0, lens-1
        flag = 0
        while low <= high:
            mid =  (low + high)//2
            if nums[mid] == target:
                flag = 1
                break
            elif nums[mid] < target:
                low =mid +1
            else :
                high =mid-1
        if flag:
            left , right = mid, mid
            while left >= 0 and nums[left] == target:
                left -=1
            while right <=(lens-1) and nums[right] == target :
                right +=1
        else :
            return [-1,-1] 
        return [left+1,right-1]
