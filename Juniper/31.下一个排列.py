#
# @lc app=leetcode.cn id=31 lang=python3
#
# [31] 下一个排列
#
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # lens = len(nums)
        # pos = 0
        # for i in range(lens-1, 0, -1):
        #     if nums[i] > nums[i-1]:
        #         temp = lens-1 
        #         while nums[temp] <= nums[i-1]:
        #             temp -=1
        #         nums[temp],nums[i-1] = nums[i-1],nums[temp]
        #         pos = i
        #         break
        # for j in range((lens-pos)//2):
        #     nums[j+pos], nums[lens-1-j] = nums[lens-1-j], nums[j+pos]

        
        lens = len(nums)
        if lens <3:
            nums.reverse()
            return 
        for i in range(lens-2, -1, -1):
            if nums[i] < nums[i+1]:
                nums[i],nums[i+1] = nums[i+1],nums[i]
                break
            else :
                k = i
                while k < lens-1 and nums[k] >= nums[k+1]:
                    nums[k],nums[k+1] = nums[k+1],nums[k]
                    k +=1
                if k < lens-1:
                    while k >=i :
                        nums[k],nums[k+1] = nums[k+1],nums[k]
                        k -= 1 
                    return 

                
    

        

                

        

