#
# @lc app=leetcode.cn id=69 lang=python3
#
# [69] x 的平方根
#
class Solution:
    def mySqrt(self, x: int) -> int:
        if x < 2:
            return x
        low = 1
        high = x-1
        mid  = low + (high-low)//2
        while low <= high:
            if mid*mid < x:
                low = mid+1 
            elif mid * mid > x:
                high = mid-1
            else:
                return mid
            mid = low + (high-low)//2
        return mid

        
        

