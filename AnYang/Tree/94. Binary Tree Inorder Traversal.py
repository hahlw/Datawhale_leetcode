# 2019-07-28 Sun

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        ret = []
        self.btit(root, ret)
        return ret

    def btit(self, root, ret):
        if root:
            self.btit(root.left, ret)
            ret.append(root.val)
            self.btit(root.right, ret)