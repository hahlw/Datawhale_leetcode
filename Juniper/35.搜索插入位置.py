#
# @lc app=leetcode.cn id=35 lang=python3
#
# [35] 搜索插入位置
#
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if not nums :
            return 0
        lens = len(nums)
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
            return mid 
        else :
            return mid+1 if nums[mid] < target else mid
      

