# 2019-07-11 Thu

class Solution:
    def jump(self, nums: List[int]) -> bool:
        if len(nums)==1 : return 0
        boundary = nums[0]
        i = 0
        c = []
        for i in range(len(nums)):
            for t2 in range(1, 1+boundary):
                if t2 + nums[t2] < nums[i+1:i+1+boundary]
        ans = 1
        for i in range(len(c)-1):
            if c[i] + nums[c[i]] < c[i+1]：
                ans += 1
        return ans

[7,0,9,6,9,6,1,7,9,0,1,2,9,0,3]