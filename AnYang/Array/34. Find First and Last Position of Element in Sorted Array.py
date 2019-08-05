# 2019-08-04 Sun

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1,-1]

        left = right = nums.index(target)

        while right < len(nums)-1 and nums[right+1] == target:
            right += 1

        return [left,right]