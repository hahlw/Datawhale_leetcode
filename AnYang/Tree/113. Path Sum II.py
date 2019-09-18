# 2019-09-17 Tue

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
    if root is None:
        return []
    self.res = []
    self.helper(root, sum, [])
    
    return self.res

def helper(self, root, sum, ret):
    if root:
        if not root.left and not root.right:
            if root.val == sum:
                ret.append(root.val)
                self.res.append(ret.copy())
                ret.pop()
        else:
            ret.append(root.val)
            self.helper(root.left, sum - root.val, ret)
            self.helper(root.right, sum - root.val, ret)
            ret.pop()