#
# @lc app=leetcode.cn id=29 lang=python3
#
# [29] 两数相除
#
class Solution:
         def divide(self, dividend: int, divisor: int) -> int:
            if not dividend or abs(dividend) < abs(divisor):
                return 0
            if dividend == -(1<<31) and divisor == -1 :
                return (1<<31) -1
            nagetive =  (dividend ^ divisor) <0        
            dividend = abs(dividend)
            divisor = abs(divisor)
            quo = 0
            for i in range(31, -1, -1):
                if not dividend < (divisor<<i) :                   
                    dividend -= (divisor<<i)
                    quo += (1<<i)
            return - quo  if  nagetive else quo

        

        

