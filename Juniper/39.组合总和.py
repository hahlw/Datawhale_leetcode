#
# @lc app=leetcode.cn id=39 lang=python3
#
# [39] 组合总和
#
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        lens = len(candidates)
        temp = []
        for i in range(lens):
            if self.check(candidates[i], target):
                if candidates[i] == target:
                    temp.append([candidates[i]])
                else:
                    t = self.match(candidates[i:], target - candidates[i])
                    if t:
                        for p in t:
                            temp.append([candidates[i]]+p)

                    else:
                        continue
        return temp
                
    def match(self,candidates,target):
        lens =  len(candidates)
        temp = []
        for i in range(lens):
            if self.check(candidates[i], target):
                if not target == candidates[i]:
                    t = self.match(candidates[i:], target - candidates[i])
                    if t:
                        for p in t :
                            temp.append([candidates[i]]+p)
                    else:
                        continue
                    #     return []
                else:
                    temp.append([candidates[i]])
        return temp



    

    def check(self, num, target):
        if num > target:
            return False
        else :
            return True

