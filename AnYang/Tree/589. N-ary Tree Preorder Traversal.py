# 2019-09-28 Sat

# 589. N-ary Tree Preorder Traversal

"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if not root: return []
        ret = [root.val]
        for c in root.children: 
            ret += self.preorder(c)
        return ret