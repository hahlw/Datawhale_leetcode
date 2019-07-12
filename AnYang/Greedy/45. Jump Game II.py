# 2019-07-12 Fri

class Solution:
    def jump(self, nums):
        l_n = len(nums)-1
        start, end, jump = 0, 0, 0
        while end < l_n:
            jump += 1
            boundary = end + 1
            for i in range(start, boundary):
                if i + nums[i] >= l_n:
                    return jump
                boundary = max(boundary, i + nums[i])
            start, end = end + 1, boundary
        return jump

[7,0,9,6,9,6,1,7,9,0,1,2,9,0,3]