# 2019-09-24 Tue

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def flatten(self, root):
        while root:
            if root.left:
                self.flatten(root.left)
                tail = root.left
                while tail.right:
                    tail = tail.right
                tail.right = root.right
                root.right = root.left
                root.left = None
            root = root.right