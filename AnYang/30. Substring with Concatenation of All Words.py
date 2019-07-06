# 2019-07-05 Fri

class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(s) < 1 or len(words) < 1 or len(s) < len(words)*len(words[0]):
            return []
        ref = []
        wordLen, wordsNum = len(words[0]), len(words)
        wordsLength = wordLen*wordsNum
        for i in range(len(words)):
            ref += indices(s, words[i])
        print(ref)
        ret = []
        for i in ref:
            try:
                if checkStr(s[i:i+wordsLength], words, wordLen, wordsNum):
                    ret.append(i)
            except:
                pass
        
        return ret
    

def checkStr(string, words, wordLen, wordsNum):
    for i in range(wordsNum):
        temW = copy.deepcopy(words)
        print(temW)
        if string[i*wordLen:(i+1)*wordLen] in temW:
            temW.remove(string[i*wordLen:(i+1)*wordLen])
        else:
            return False
    return True


def indices(lst, element):
    result = []
    offset = -1
    while True:
        try:
            offset = lst.index(element, offset+1)
        except ValueError:
            return result
        result.append(offset)



""" 内存超限了
from itertools import permutations
class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        if len(s) < 1 or len(words) < 1 or len(s) < len(words)*len(words[0]):
            return []
        perm = set(permutations(words))
        print(perm)
        ref = []
        for i in perm:
            ref.append(''.join(i))
        ret = []
        for d in ref:
            ret += indices(s,d)
        return ret
    
def indices(lst, element):
    result = []
    offset = -1
    while True:
        try:
            offset = lst.index(element, offset+1)
        except ValueError:
            return result
        result.append(offset)
 """