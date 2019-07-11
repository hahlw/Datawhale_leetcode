#
# @lc app=leetcode.cn id=51 lang=python3
#
# [51] N皇后
#
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        self.pos = [0]*n
        self.res = []
        self.queen(0,n)
        return self.res
    def queen(self, row, n):      
        for col in range(n):
            if self.check(row, col):
                self.pos[row] = col
                if row == n-1:
                    temp = []
                    for i in range(n):
                        temp.append('.'*self.pos[i]+'Q'+'.'*(n-1-self.pos[i]))
                    self.res.append(temp)
                    return
                self.queen(row + 1, n)
    def check(self,  row, col):
        for i in range(row):
            if  self.pos[i] == col or (self.pos[i] - (row-i)) == col or self.pos[i]+(row-i)==col:
                return False
        return True



        

