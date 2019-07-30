#
# @lc app=leetcode.cn id=287 lang=python3
#
# [287] 寻找重复数
#
class Solution:
    def findDuplicate(self, nums: List[int]) -> int:
        # 10.31 %
        slow = nums[0]
        fast = nums[nums[0]]
        while not nums[slow] == nums[fast] :
            slow = nums[slow]
            fast = nums[nums[fast]]
            if  fast == slow:
                fast = 0
                while not nums[slow] == nums[fast]:
                    fast = nums[fast]
                    slow = nums[slow]
        return nums[slow]
        
        # 14.53 %
        # nums.sort()
        # lens = len(nums)
        # for i in range(1,lens):
        #     if nums[i] == nums[i-1]:
        #         return nums[i]
        # 17.07 %
        # sets = set()
        # for num in nums:
        #     if num in sets:
        #         return num
        #     sets.add(num)

        # # 12.27 %  二分法
        # lens = len(nums)
        # left = 1
        # right = lens-1
        
        # while left < right :
        #     # mid  = left + (right - left)//2
        #     mid = (left + right) >> 1
        #     cnt = 0
        #     for num in nums:
        #         if num <= mid:
        #             cnt +=1
        #     if cnt > mid:
        #         right = mid
        #     else :
        #         left = mid +1
        # return left 



        
        

