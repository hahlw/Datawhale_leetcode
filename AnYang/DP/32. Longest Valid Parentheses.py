# 2019-08-16 Fri

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack, res = [], 0
        for i, c in enumerate(s):
            if c == '(': 
                stack.append(i)
            else:
                if stack and s[stack[-1]] == '(':
                    stack.pop()
                    res = max(res, i+1) if not stack else max(res, i - stack[-1])
                else:
                    stack.append(i)
        return res

def main():
    try:
        line = "(((()))))()()()()"            
        ret = Solution().longestValidParentheses(line)

        out = str(ret);
        print(out)
    except StopIteration:
        pass

if __name__ == '__main__':
    main()