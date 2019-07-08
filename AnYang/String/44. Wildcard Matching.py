# 2019-07-08 Mon

class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        if not s:
            if not p or p.count('*') == len(p): 
                return True
            else: 
                return False
        if s and not p: 
            return False

        ls, lp = len(s), len(p)
        i = j = 0
        match = star = -1

        if lp - p.count('*') > ls:
                return False
        
        while i < ls:
            if j < lp and p[j] == '*':
                match = i
                star = j
                j += 1
            elif j < lp and ( p[j] == '?' or p[j] == s[i] ):
                i += 1
                j += 1
            elif star > -1:
                i = match + 1
                j = star + 1
                match += 1
            else:
                return False
        
        while j < lp and p[j] == '*':
            j += 1
        return j == lp