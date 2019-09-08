# 2019-09-08 Sun

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root):
        if not root: 
            return []
        ret = []
        self.dfs(root,0,ret)
        return ret
    def dfs(self, root, layer, ret):
        if not root:
            return 
        if len(ret) < layer +1:
            ret.append([])
        ret[layer].append(root.val)
        self.dfs(root.left,layer + 1, ret)
        self.dfs(root.right, layer+1, ret)