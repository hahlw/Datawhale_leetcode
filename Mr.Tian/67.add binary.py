class Solution:
    def addBinary(self, a: str, b: str) -> str:
        if len(a) < len(b):
            a, b = b, a
        
        b = "0" * (len(a) - len(b)) + b
        
        ans = ""
        pos = -1
        carry = 0
        

        while pos != -(len(b) + 1):
            tmp = int(a[pos]) + int(b[pos]) + carry
            if tmp >= 2:
                carry = 1
                tmp -= 2
            else:
                carry = 0
            
            ans += str(tmp)
            pos -= 1
        
        if carry == 1:
            ans += '1'
        
        return ans[::-1]