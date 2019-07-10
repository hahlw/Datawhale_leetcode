# 2019-07-09 Tue
# 这题不值得做。。。

class Solution:
    def isNumber(self, s: str) -> bool:
        if not s:
            return False
        if len(s.split()) > 1 or len(s.split()) < 1 :
            print('aa')
            return False
        s = (s.split())[0]
        if '-+' in s or '+-' in s or '++' in s or '--' in s:
            return False
        if s[-1] == '-' or s[-1] == '+':
            return False
        try:
            if s.index('.e') == 0:
                return False
        except:
            pass

        ref1 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.', '-', '+', 'e'}
        ref2 = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'}
        c1 = c2 = c3 = c4 = 0
        for l in s:
            if l == '.':
                c1 += 1
            if l == '-':
                c2 += 1
            if l == '+':
                c3 += 1
            if l == 'e':
                c4 += 1
            if l not in ref1:
                return False
            if c1 > 1 or c2 > 2 or c3 > 2 or c4 > 1 :
                print('b')
                return False
        
        if c1 == 1:
            td = s.index('.')
            try:
                if (s[td-1] not in ref2):
                    if s[td-1] != '-' and s[td-1] != '+':
                        print('55')
                        return False
                if td == len(s)-1:
                    if s[td-1] not in ref2:
                        print('44')
                        return False
                elif s[td+1] not in ref2 and s[td+1] != 'e':
                    print('111')
                    return False
            except:
                return False
        if c1 == 1 and c4 == 1:
            if s.index('.') > s.index('e'):
                return False
        if c2 == 1:
            try:
                if s[s.index('-')+1] not in ref2 and s[s.index('-')+1] != '.':
                    print('====')
                    return False
            except:
                return False
            try: 
                if s.index('-') != 0 and s[s.index('-')-1] != 'e':
                    print('--')
                    return False
            except:
                pass
            
        if c3 == 1:
            try:
                if s[s.index('+')+1] not in ref2 and s[s.index('+')+1] != '.':
                    print('22')
                    return False
            except:
                return False
            try: 
                if (s.index('+') != 0 and s[s.index('+')-1] != 'e'):
                    print('33')
                    return False
            except:
                pass
        if c4 == 1:
            try:
                if s.index('e') == 0 or s.index('e') == len(s)-1 or (s[s.index('e')-1] not in ref2 and s[s.index('e')-1] != '.'):
                    print('++')
                    return False
            except:
                print('000')
                return False
        return True

""" 捷径https://leetcode.com/problems/valid-number/discuss/329883/one-liner-python """
        # try:
        #     s = float(s)
        #     return True
        # except:
        #     return False