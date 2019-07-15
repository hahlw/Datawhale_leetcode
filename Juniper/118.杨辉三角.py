#
# @lc app=leetcode.cn id=118 lang=python3
#
# [118] 杨辉三角
#
class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        res = []
        for i in range(numRows):
            if  res:
                res.append([1]+[res[i-1][j-1]+res[i-1][j] for j in range(1,i)]+[1])
            else :
                res.append([1])
        return res 
        

