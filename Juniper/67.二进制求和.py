#
# @lc app=leetcode.cn id=67 lang=python3
#
# [67] 二进制求和
#
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        res = ''
        carry = 0
        if len(a) < len(b):
            a, b = b, a
        lens = len(a)
        for i in range (lens):
            if i < len(b):
                temp = int(a[-i-1])+int(b[-i-1]) +carry
            elif carry == 0:
                return a[:-i]+res
            else :
                temp = int(a[-i-1])+carry
            if temp >1 :
                temp = temp-2
                carry = 1
            else :
                carry = 0
            res = str(temp)+res
            # print(temp,carry,res)
        return '1'+res  if  carry else res
        

