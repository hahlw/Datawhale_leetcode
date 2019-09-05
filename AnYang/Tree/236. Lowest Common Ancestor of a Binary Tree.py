# 2019-09-01 Sun

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        # # print(root.val, p.val, q.val)
        # # print(L, R)
        if root == None or root.val == q.val or root.val == p.val:
            return root
        L = self.lowestCommonAncestor(root.left,  p, q)
        R = self.lowestCommonAncestor(root.right, p, q)
        
        if not R:
            return L
        elif not L:
            return R
        else:
            return root

"""  
如果是完全二叉树的话
    找祖先的时候用到 
    parent = (idx - 2) // 2

    找到p,q两个节点的idx，再逆着找共同的parent。
"""