# 2019-10-22 Tue

# 530. Minimum Absolute Difference in BST

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:

    a, b = float("-inf"), float("inf")
	
    def getMinimumDifference(self, r: TreeNode) -> int:
        if not r: return r
        self.getMinimumDifference(r.left)
        self.b, self.a = min(self.b, r.val-self.a), r.val
        self.getMinimumDifference(r.right)
        return self.b