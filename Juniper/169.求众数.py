#
# @lc app=leetcode.cn id=169 lang=python3
#
# [169] 求众数
#
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        # Boyer-Moore 投票算法
        cnt = 0
        major = None
        for num in nums:
            if not cnt :
                major = num
            cnt += 1 if major == num else -1
        return major

        

