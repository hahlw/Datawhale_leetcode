# 2019-09-22 Sun

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        def helper(node):
            if not node:
                return None

            helper(node.left)
            helper(node.right)

            node.left, node.right = node.right, node.left
        helper(root)
        return root