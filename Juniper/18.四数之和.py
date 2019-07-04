#
# @lc app=leetcode.cn id=18 lang=python3
#
# [18] 四数之和
#
class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        lens = len(nums)
        if lens < 4:
            return []
        lis = []
        nums.sort()
        for j in range(lens-3):
            if j == 0 or nums[j] > nums[j-1]:
                temp = target - nums[j]
                for i in range(j+1, lens-2):
                    if i == j+1 or nums[i]>nums[i-1]:  #去重复
                        left =i+1
                        right =lens-1
                        if nums[i]+nums[i+1]+nums[i+2]> temp:
                            continue 
                        if nums[i]+nums[lens-1]+nums[lens-2]< temp:
                            continue 
                        while left < right:
                            temp_sum = nums[i]+nums[left]+nums[right]
                            if temp_sum < temp:
                                left = left + 1
                            elif temp_sum > temp:
                                right = right -1                               
                            else :
                                lis.append([nums[j],nums[i],nums[left],nums[right]])
                                left = left + 1
                                right = right - 1
                                # 去重复
                                while left < right and nums[left] == nums[left - 1]:
                                    left += 1
                                while right > left and nums[right] == nums[right + 1]:
                                    right -= 1
        return lis
            

                