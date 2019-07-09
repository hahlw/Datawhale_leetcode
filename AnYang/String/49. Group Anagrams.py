# 2019-07-09 Tue

# 下次用dp的方法试试
class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ref = []
        ret = []
        for s in strs:
            t = ''.join(sorted(s))
            print(t,s)
            if t not in ref:
                ref.append(t)
                ret.append([s])
            else:
                ret[ref.index(t)].append(s)
        return ret