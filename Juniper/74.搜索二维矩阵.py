#
# @lc app=leetcode.cn id=74 lang=python3
#
# [74] 搜索二维矩阵
#
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        
        if not matrix:
            return False
        row = len(matrix)
        col = len(matrix[0])     
        # # 5.79 %
        left = 0
        right = col*row-1
        while left <= right :
            mid = (left + right)//2
            index1 = mid // col 
            index2 =  mid % col
            if target < matrix[index1][index2]:
                right = mid -1
            elif target > matrix[index1][index2]:
                left = mid +1
            else :
                return True
        return False
        # # 5.79 %
        # i = 0
        # j = col-1
        # while i < row and j >= 0:
        #     if matrix[i][j] < target:
        #         i +=1
        #     elif matrix[i][j] > target:
        #         j -=1
        #     else:
        #         return True
        # return False
    
       
  
   

