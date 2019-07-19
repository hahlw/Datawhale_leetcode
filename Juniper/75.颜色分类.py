#
# @lc app=leetcode.cn id=75 lang=python3
#
# [75] 颜色分类
#
class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 83.79 %
        cnt0 = cnt1 = cnt2 =0
        lens = len(nums)
        for i in range(lens):
            if nums[i] == 0:
                cnt0 += 1
            elif nums[i] == 1:
                cnt1 +=1
            elif nums[i] == 2:
                cnt2 +=1
        for i in range(lens):
            if i < cnt0:
                nums[i] =0
            elif i < cnt1+cnt0:
                nums[i] =1
            else :
                nums[i] = 2
        
        # 83.79 %
        lens = len(nums)
        left = i = 0 
        right = lens-1
        key = 1
        while i <= right:
            if nums[i] < key:
                if left == i:
                    i +=1
                    left +=1
                    continue
                nums[left], nums[i] = nums[i], nums[left]  
                i +=1
                left +=1
            elif nums[i] > key:
                if i == right:
                    i +=1
                    right -=1
                    continue
                nums[right], nums[i] = nums[i], nums[right]  
                right -=1
            else :
                i +=1


