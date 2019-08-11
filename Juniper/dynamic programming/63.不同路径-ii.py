#
# @lc app=leetcode.cn id=63 lang=python3
#
# [63] 不同路径 II
#
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[0][0]:
            return 0
        row  = len(obstacleGrid)
        col = len(obstacleGrid[0])
        dp = [[1]*col for i in range(row)]
        for i in range(row):
            for j in range(col): 
                if not obstacleGrid[i][j]:
                    if i or j:
                        dp[i][j] = (dp[i-1][j] if i>0 else 0) + (dp[i][j-1] if j >0 else 0)
                else :
                    dp[i][j] = 0
        return dp[-1][-1]

        
