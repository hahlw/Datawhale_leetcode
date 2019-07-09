# 2019-07-09 Tue
# 纯属充数
class Solution:
    def defangIPaddr(self, address: str) -> str:
        return address.replace('.', '[.]')