# 2019-09-05 Thu

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isValidBST(self, root: TreeNode) -> bool:
        ret = []
        
        self.helper(root, ret)
        
        for i in range(len(ret)-1):
            if ret[i] >= ret[i+1]:
                return False
        return True
        
        
    def helper(self, root, ref):
        if root:
            if root.left:
                self.helper(root.left, ref)
            ref.append(root.val)
            if root.right:
                self.helper(root.right, ref)