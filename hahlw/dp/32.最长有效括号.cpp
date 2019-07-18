/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0||s.size()==1)return 0;
        stack<int >stk;
        int len=0;
        stk.push(-1);
        for(int i=0;i<s.size();i++){
            int t=stk.top();
            if(t!=-1&&s[t]=='('&&s[i]==')'){
                stk.pop();
                len=max(len,i-stk.top());
            }
            else stk.push(i);
        }
        return len;
    }
};

