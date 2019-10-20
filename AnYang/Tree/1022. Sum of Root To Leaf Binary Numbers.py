# 2019-10-20 Sun

# 1022. Sum of Root To Leaf Binary Numbers


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def sumRootToLeaf(self, root: TreeNode) -> int:
        return self.dfs2(root, None)
    
    def dfs2(self, node, parent_sum=None):
        if parent_sum == None:
            parent_sum = 0
        if node:
            parent_sum = parent_sum * 2 + node.val
            if node.left or node.right:
                return self.dfs2(node.left, parent_sum) + self.dfs2(node.right, parent_sum)
            else:
                return parent_sum
        else:
            return 0