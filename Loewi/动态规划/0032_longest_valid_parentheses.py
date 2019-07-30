#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jul 30 16:10:35 2019

@author: loewi
32. 最长有效括号
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。

示例 1:

输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:

输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-valid-parentheses
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。


解析：
https://blog.csdn.net/weixin_42317507/article/details/97796400
"""

class Solution:
    def longestValidParentheses(self, s: str) -> int:
        
        res = 0
        dp = [0]*len(s)
        
        for i in range(1, len(s)):
            if s[i] == ')' and s[i-1]=='(':
                dp[i] = dp[i-2] + 2
            if s[i] == ')' and s[i-1] == ')':
                if i-dp[i-1] >= 1 and s[i-dp[i-1]-1] =='(':
                    dp[i] = dp[i-1] + 2 + dp[i-dp[i-1]-2]*(i-dp[i-1] >= 2) 
                    
            res = max(res, dp[i])
            
        return res
                    