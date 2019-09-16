# 2019-09-16 Mon

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        if not root:
            return False
        sum -= root.val
        if (sum == 0) and (not root.left) and (not root.right):
            return True
        else:
            return self.hasPathSum(root.left, sum) or self.hasPathSum(root.right, sum)