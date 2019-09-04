# 2019-09-04 Wed

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p == None or q == None:
            return True if p == None and q == None else False
        return False if p.val != q.val else self.isSameTree(q.left,p.left) and self.isSameTree(p.right, q.right)