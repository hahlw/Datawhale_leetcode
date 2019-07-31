# 2019-07-31 Wed

class Solution(object):
    def _maxPathSum(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        if not root: return -sys.maxint
        
        l = max(0, self._maxPathSum(root.left))
        r = max(0, self._maxPathSum(root.right))
        self.ans = max(self.ans, root.val + l + r)
        return root.val + max(l,r)

    def maxPathSum(self, root):
        self.ans = -sys.maxint
        self._maxPathSum(root)
        return self.ans