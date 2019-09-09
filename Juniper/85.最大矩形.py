#
# @lc app=leetcode.cn id=85 lang=python3
#
# [85] 最大矩形
#
class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        # row = len(matrix)
        # col = len(matrix[0])
        # dp = [[0]*col for i in range(row)]
        # max_rect = 0
        # for i in range(1,row):
        #     for j in range(1,col):
        #         if matrix[i][j]:
        #             if matrix[i-1][j-1] and matrix[i-1][j] and matrix[i][j-1]:
        #                 dp[i][j] = dp[i-1][j-1] + dp[i-1][j] + dp[i][j-1] + str(matrix[i][j])
        #             else:
        #                 dp[i][j] = matrix[i][j]
        #         else :
        #             dp[i][j] = 0
        #         max_rect = max(max_rect,dp[i][j])
        # return max_rect
        if not matrix or not matrix[0]:
            return 0
        nums = [int(''.join(row), base=2) for row in matrix]
        ans, N = 0, len(nums)
        for i in range(N):
            j, num = i, nums[i]
            while j < N:
                num = num & nums[j]
                if not num:
                    break
                l, curnum = 0, num
                while curnum:
                    l += 1
                    curnum = curnum & (curnum << 1)
                ans = max(ans, l * (j-i+1))
                j += 1
        return ans

        
