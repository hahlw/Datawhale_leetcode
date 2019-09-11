# 2019-09-10 Tue

"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root:
            return 0
        stack=[root]
        res=0
        while stack:
            tem=[]
            res+=1
            for i in stack:
                for j in i.children:
                    tem.append(j)
            stack=tem[:]
        return res