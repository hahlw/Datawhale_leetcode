# 2019-09-29 Sun

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
	def isUnivalTree(self, root: TreeNode) -> bool:
		if not root:
			return True
		val=root.val
		return self.helper(root,val)


	def helper(self,root,val):
		if not root:
			return True
		if root.val!=val:
			return False
		left=self.helper(root.left,val)
		right=self.helper(root.right,val)
		return left and right