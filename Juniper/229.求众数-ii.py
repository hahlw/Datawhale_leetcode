#
# @lc app=leetcode.cn id=229 lang=python3
#
# [229] 求众数 II
#
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        # Boyer-Moore 投票算法
        lens = len(nums)
        if lens == 0:
            return []
        cnt1 = 0
        cnt2 = 0
        major1 = None
        major2 = None
        for i in range(lens):
            if nums[i] == major1:
                cnt1 +=1
            elif nums[i] == major2 :
                cnt2 +=1
            elif cnt1 == 0 :
                major1 = nums[i]
                cnt1 =1
            elif cnt2 == 0:
                major2 = nums[i]
                cnt2 =1
            else :
                cnt1 -=1
                cnt2 -=1
        cnt1 = cnt2 = 0
        return [n for n in (major1, major2) if nums.count(n) > len(nums) // 3]

