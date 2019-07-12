#
# @lc app=leetcode.cn id=57 lang=python3
#
# [57] 插入区间
#
class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        # print(intervals.append(newInterval))
        def merge(nums):
                res = []
                lens = len(nums)
                i = 0
                nums.sort(key=lambda x:x[0])
                while i < lens:
                    j = i
                    r = nums[i][1]
                    if i < lens-1 and r >= nums[i+1][0]:
                        while i < lens-1 and r >= nums[i+1][0]:
                            if r < nums[i+1][1]:
                                r = nums[i+1][1]
                            i +=1
                        res.append([nums[j][0], r])
                    else:
                        res.append(nums[i])
                    i +=1    
                return res
        
        return merge(intervals+[newInterval])
    


