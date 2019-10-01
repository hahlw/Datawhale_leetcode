# 2019-10-01 Tue

"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    # def __init__(self):
        # self.l = []
    def postorder(self, root: 'Node') -> List[int]:
        if not root: return []
        if not root.children: return [root.val]
        l = []
        for c in root.children: 
            l += self.postorder(c)
        return l + [root.val]