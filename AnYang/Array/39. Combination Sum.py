# 2019-08-06 Tue

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.resList = []
        candidates.sort()
        self.dfs(candidates,[],target,0)
        return self.resList

    def dfs(self,candidates,sublist,target,last):
        if target == 0:
            self.resList.append(sublist[:])
        if target < candidates[0]:
            return
        for n in candidates:
            if n > target:
                return
            if n < last:
                continue
            sublist.append(n)
            self.dfs(candidates,sublist,target-n,n)
            sublist.pop()