# 2019-11-02 Sat

# 543. Diameter of Binary Tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        ans = [-100]
        self.ht(root, ans)

        return ans[0]

    def ht(self, root, ans):
        if not root:
            return -1

        lh = self.ht(root.left, ans)
        rh = self.ht(root.right, ans)
        ans[0] = max(ans[0], lh + rh + 2)
        return 1 + max(lh, rh)