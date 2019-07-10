# 2019-07-10 Wed

class Solution:
    def canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        if sum(cost) > sum(gas):
            return -1
        lc = len(cost)
        cost += cost
        gas += gas
        
        for i in range(2*lc - 1):
            gas[i] = gas[i] - cost[i]
        ref, ans = 0, 0
        for i in range(lc):
            ref += gas[i]
            if ref < 0:
                ans = (i + 1) % lc
                ref = 0
        return ans