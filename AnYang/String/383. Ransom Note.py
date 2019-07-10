# 2019-07-10 Wed
class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:        
        for i in ransomNote:
            if i not in magazine:
                return False
            magazine = magazine[:magazine.index(i)] + magazine[magazine.index(i)+1:]
        return True