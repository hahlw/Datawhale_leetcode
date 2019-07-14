# 2019-07-13 Sat

# 455. Assign Cookies

# 先占个坑，借鉴dalwise的解法
# 用两个指针分别两个排好序的list
class Solution:
    def findContentChildren(self, g, s):
        g.sort()
        s.sort()
        i = 0
        for e in s:
            if i == len(g):
                break
            if e >= g[i]:
                i += 1
        return i