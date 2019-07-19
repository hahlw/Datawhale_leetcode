#
# @lc app=leetcode.cn id=167 lang=python3
#
# [167] 两数之和 II - 输入有序数组
#
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        lens = len(numbers)
        left = 0
        right = lens-1
        while left < right:
            temp = numbers[left] + numbers[right]
            if temp > target:
                right -= 1
                while numbers[right] == numbers[right+1] :
                    right -= 1

            elif temp < target:
                left += 1
                while numbers[left] == numbers[left-1] :
                    left += 1
            else:
                return [left+1, right+1]

