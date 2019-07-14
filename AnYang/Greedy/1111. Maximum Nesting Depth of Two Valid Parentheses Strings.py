# 2019-07-14 Sun

""" 
这题对我来说最难的是读不懂题意。

大体上是说将字符串S分为A和B。
1, len(A) + len(B) == len(S)
2, A, B都是有效字符串（VPS）

最后题目的要求是，将S分为A和B，让（A+B）的深度最小。
然后就是将属于A的字符用‘0’来表示，属于B的字符用‘1’来表示。e.g.:
S = "(((())))"
ANS = [0, 0, 1, 1, 1, 1, 0, 0]
"""

""" 
用两个栈来分别记录A和B。
保持A和B的长度尽量相等。(abs(len(A)-len(B))) <= 1
"""

""" 
下面这个解的空间使用保持稳定，100%
速度在7%到100%之间波动。太不靠谱了。
"""
class Solution:
    def maxDepthAfterSplit(self, seq: str):
        A = 0
        B = 0
        flg = []
        ans = []
        for c in seq:
            if c == '(':
                if A <= B:
                    A += 1
                    ans.append(0)
                    flg.append(0)
                else:
                    B += 1
                    ans.append(1)
                    flg.append(1)
            else:
                if not flg.pop():
                    ans.append(0)
                    A -= 1
                else:
                    ans.append(1)
                    B -= 1
        return ans