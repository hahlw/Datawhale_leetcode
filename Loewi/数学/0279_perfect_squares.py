#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Jul  6 22:06:32 2019

@author: loewi

279. 完全平方数

给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

示例 1:

输入: n = 12
输出: 3 
解释: 12 = 4 + 4 + 4.
示例 2:

输入: n = 13
输出: 2
解释: 13 = 4 + 9.

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/perfect-squares

"""


class Solution:
    def numSquares(self, n: int) -> int:
        candidates = set([ i*i for i in range(int(n**0.5)+1)])
        
        def bfs(nums):
            if nums & candidates: return 1
            
            tmp = set([num - candi for num in nums for candi in candidates if num - candi >= 0 ])
            
            return bfs(tmp)+1
        
        return bfs(set([n]))
            