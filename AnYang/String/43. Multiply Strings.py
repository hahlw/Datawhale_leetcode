# 2019-07-07 Sun

class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        n1 = self.str2num(num1)
        n2 = self.str2num(num2)
        return str(n1*n2)
    def str2num(self, num):
        ret = 0
        for n in range(len(num)):
            ret += int(num[n]) * 10**(len(num)-1-n) 
        return ret