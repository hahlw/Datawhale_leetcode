# 2019-08-03 Sat

class Solution:
    def search(self, nums: List[int], target: int) -> int:
        ln = len(nums)
        if ln == 0:
            return -1
        left = 0
        right = ln - 1
        while left + 1 < right :
            mid = (left+right)//2
            if  nums[mid]  == target:
                return mid
            if nums[mid] >= nums[left]:
                if target >= nums[left] and target < nums[mid]:
                    right = mid
                else:
                    left = mid
            else:
                if target <= nums[right] and target > nums[mid]:
                    left = mid
                else:
                    right = mid
        if nums[left] == target:
            return left
        if nums[right] == target:
            return right
        return -1