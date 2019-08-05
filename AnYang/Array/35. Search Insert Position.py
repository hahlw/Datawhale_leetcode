# 2019-08-05 Mon

class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        
        l = len(nums)//2
        left = 0
        right = len(nums)-1
        
        while(left + 1 != right and left != right):
            if(target == nums[l]):
                return l
            if(target <= nums[l]):
                right = l
                l = (left + right)//2
            elif(target > nums[l]):
                left = l
                l = (left + right)//2
                
        if target > nums[right]:
            return right + 1
        if target <= nums[left]:
            return 0
        return right