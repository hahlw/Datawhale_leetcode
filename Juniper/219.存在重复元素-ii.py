#
# @lc app=leetcode.cn id=219 lang=python3
#
# [219] 存在重复元素 II
#
class Solution:
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        lens = len(nums)
        dic = dict()
        for i in range(lens):           
            if nums[i] in dic.keys():
                if i - dic[nums[i]] <=k:
                    return True
            dic[nums[i]] = i
        return False
        

