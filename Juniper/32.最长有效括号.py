#
# @lc app=leetcode.cn id=32 lang=python3
#
# [32] 最长有效括号
#
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        # lens = len(s)
        # if not lens:
        #     return 0
        # dp = [0]*lens
        # max_lens = 0
        # for i in range(1,lens):
        #     if s[i]==')':
        #         if s[i-1]=='(':
        #             if i <2:
        #                 dp[i] = 2
        #             else :
        #                 dp[i] = dp[i-2] +2
        #         elif i-dp[i-1]-1 >= 0 and s[i-dp[i-1]-1]=='(':
        #             dp[i] = dp[i-1]+(dp[i-dp[i-1]-2] if (i - dp[i - 1]) >= 2 else 0) +2
        #     max_lens = max(max_lens, dp[i])
        # return max_lens 

        rr = rl = ll = lr = max_lens = 0
        lens  = len(s)
        for i in range(lens):
            if s[i] == '(':
                ll += 1
            else :
                lr += 1
            if s[-1-i] == '(':
                rl += 1
            else:
                rr += 1 
            if ll == lr:
                max_lens = max(max_lens, ll*2)
            elif lr > ll:
                lr = 0
                ll = 0
            if rl == rr:
                max_lens = max(max_lens, rr*2)
            elif rl > rr:
                rr = 0
                rl = 0
        return max_lens


    

        


