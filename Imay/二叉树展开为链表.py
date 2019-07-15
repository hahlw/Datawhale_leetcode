# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        """
        :type root: TreeNode
        :rtype: None Do not return anything, modify root in-place instead.
        """
        def helper(root):
            if root==None:
                return
            helper(root.left)
            helper(root.right)
            if root.left != None: # 后序遍历
                pre = root.left # 令 pre 指向左子树
                while pre.right: pre = pre.right # 遍历所有左子树的右节点
                pre.right = root.right # 令左子树中的最右节点的右子树 指向 根节点的右子树
                root.right = root.left # 令根节点的右子树指向根节点的左子树
                root.left = None # 置空根节点的左子树
            root = root.right # 令当前节点指向下一个节点
        helper(root)
           
        
        
        
        
        
        
        
        
        
        
        
        
        
