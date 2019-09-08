# 2019-09-07 Sat

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

# 借鉴: nuclearoreo

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        return self._isSymmetric(root, root)
        
    def _isSymmetric(self, n1, n2):
        if n1 == None and n2 == None: return True
        if n1 == None or n2 == None: return False
        
        return n1.val == n2.val and \
            self._isSymmetric(n1.left, n2.right) and \
            self._isSymmetric(n2.right, n1.left)
