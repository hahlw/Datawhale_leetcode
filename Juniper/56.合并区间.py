#
# @lc app=leetcode.cn id=56 lang=python3
#
# [56] 合并区间
#
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        lens = len(intervals)
        i = 0
        intervals.sort(key=lambda x:x[0])
        while i < lens:
            j = i
            r = intervals[i][1]
            if i < lens-1 and r >= intervals[i+1][0]:
                while i < lens-1 and r >= intervals[i+1][0]:
                    if r < intervals[i+1][1]:
                        r = intervals[i+1][1]
                    i +=1
                res.append([intervals[j][0], r])
            else:
                res.append(intervals[i])
            i +=1    
        return res


        

