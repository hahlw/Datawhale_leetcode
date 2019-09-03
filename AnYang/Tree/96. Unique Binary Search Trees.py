# 2019-09-03 Tue

class Solution:
    def numTrees(self, n: int) -> int:
        if n < 2:
            return 0 if n < 1 else 1
        ret = [0]*(n+1)
        ret[0] = 1
        ret[1] = 1
        for i in range(2, n+1):
            k = 0
            for j in range(i-1, -1, -1):
                ret[i] += ret[j] * ret[k]
                k += 1
        return ret[n]