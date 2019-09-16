# 2019-09-14 Sat

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def minDepth(self, root) -> int:
        return self.helper(root, 0) if root else 0
    
    def helper(self, node, ret) -> int:     
        if not node:
            return ret
        if not node.left:
            return self.helper(node.right, ret+1)
        if not node.right:
            return self.helper(node.left, ret+1)
        left = self.helper(node.left, ret+1)
        right = self.helper(node.right, ret+1)
        return min(left, right)