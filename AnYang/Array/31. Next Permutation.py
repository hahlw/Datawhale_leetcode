# 2019-08-10 Sat

class Solution:
    def nextPermutation(self, nums):
        l = ll = len(nums)
        l -= 1
        while l > 0:
            if nums[l-1] < nums[l]: break
            l -= 1
        if l:
            p = l
            while p < ll and nums[p] > nums[l-1]: 
                p += 1 
            nums[l-1], nums[p-1] = nums[p-1], nums[l-1]
        for i in range((ll-l)//2):
            nums[l+i], nums[-i-1] = nums[-i-1], nums[l+i]