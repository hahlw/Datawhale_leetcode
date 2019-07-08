#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Jun 25 15:12:59 2019

@author: loewi

204. 计数质数
统计所有小于非负整数 n 的质数的数量。

示例:

输入: 10
输出: 4
解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
"""


class Solution:
    def countPrimes(self, n: int) -> int:
 
        if n < 3: return 0
        
        res = [ 1 for _ in range(n) ]
        
        res[0], res[1] = 0,  0

        for i in range(2, int(n**0.5) + 1):

            res[i*i::i] = len(res[i*i::i])*[0]
 
        return sum(res)
    

        
    
    
    
