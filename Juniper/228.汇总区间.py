#
# @lc app=leetcode.cn id=228 lang=python3
#
# [228] 汇总区间
#
class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        lens = len(nums)
        if not lens:
            return
        elif lens == 1:
            return [str(nums[0])] 
        left = right = nums[0]
        res = []
        for i in range(1,lens):
            if not nums[i] == right + 1:
                if left == right:
                    res.append(str(left))
                else :
                    res.append(str(left)+'->'+str(right))
                left = right = nums[i]
            else :
                right +=1
            if i == lens-1:
                if left == right:
                    res.append(str(left))
                else :
                    res.append(str(left)+'->'+str(right))
        
        return res

        

