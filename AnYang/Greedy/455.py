# 2019-07-13 Sat

# 455. Assign Cookies

# 先占个坑，借鉴dalwise的解法
class Solution:
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        res = 0
        i = 0
        for e in s:
            if i == len(g):
                break
            if e >= g[i]:
                res += 1
                i += 1
        return res