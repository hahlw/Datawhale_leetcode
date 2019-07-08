# 2019-07-06 Sat

# 看了半天才读懂题
class Solution:
    def countAndSay(self,n):
        if n == 1:
            return '1'
        s = "1"
        for j in range(1, n):
            t = s[0]
            temp = ""
            count = 0
            for i in range(len(s)):
                if(t==s[i]):
                    count += 1
                else:
                    temp = temp+str(count)+t
                    t = s[i]
                    count = 1
            s = temp+str(count)+t
        return s