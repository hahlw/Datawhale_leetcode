# 2019-07-19 Fri

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # subStr = []
        # lMax = 0
        # lSub = 0
        # for i in s:
        #     if i in subStr:
        #         subStr = subStr[(subStr.index(i)+1)::]
        #         lSub = len(subStr)
        #         subStr.append(i)
        #     else:
        #         subStr.append(i)
        #         lSub = len(subStr)
        #         # print(subStr)
        #     lMax = max(lMax, lSub)
        # return lMax
        
        
        if len(s) < 2:
            return len(s)
        
        l = 0
        ret = 1
        ls = len(s)
        for idx, i in enumerate(s):
            if i in s[l:idx]:
                ret = max(ret, idx-l)
                l = l + s[l:idx].index(i) +1
        ret = max(ret, ls - l)
        return ret

""" dict """
# class Solution:
#     def lengthOfLongestSubstring(self, s):
#         d,m,c,st={},0,0,0
#         for i, e in enumerate(s): 
#             if e in d and d[e]>=st: m,c,st=max(m,c),i-d[e],d[e]+1
#             else: c+=1
#             d[e]=i
#         return max(m,c)