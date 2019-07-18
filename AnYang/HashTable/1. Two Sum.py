# 2019-07-18 Thu

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for idx, item in enumerate(nums):
            if target - item in nums:
                return [idx, nums.index(target - item)]