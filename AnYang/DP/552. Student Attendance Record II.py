# 2019-07-21 Sun

class Solution:
    def checkRecord(self, n):
        if n == 1:
            return 3
        M = 10**9 + 7
        dp = [1, 2, 4, 7]
        for i in range(4, n+1):
            # print(i,dp)
            dp.append((2*dp[i-1] - dp[i-4])%M)
        
        sum = dp[n] % M
        for i in range(1, n+1):
            sum += (dp[i-1]*dp[n-i])
        return sum%M