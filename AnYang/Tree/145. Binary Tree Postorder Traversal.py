# 2019-09-19 Thu


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ret = []

    def postorderTraversal(self, root: TreeNode):
        if root:
            self.postorderTraversal(root.left)
            self.postorderTraversal(root.right)
            if root.val:
                self.ret.append(root.val)
        return self.ret