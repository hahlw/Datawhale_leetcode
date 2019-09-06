# 2019-09-06 Fri

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []
        return self.generateSubTree(1, n)


    def generateSubTree(self, start, end):
        res = []
        if start > end:
            res.append(None)
            return res
        for i in range(start, end+1):
            left_res = self.generateSubTree(start, i-1)
            right_res = self.generateSubTree(i+1, end)
            for ls in left_res:
                for rs in right_res:
                    newRoot = TreeNode(i) 
                    newRoot.left = ls
                    newRoot.right = rs
                    res.append(newRoot)

        return res