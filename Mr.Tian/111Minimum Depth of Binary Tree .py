# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def minDepth(root):
        if not root:
            return 0
        height = 1
        queue = [root, None]
        while queue:
            node = queue.pop(0)
            if node:
                node_left_exist = False
                node_right_exist = False
                if node.left:
                    node_left_exist = True
                    queue.append(node.left)
                if node.right:
                    node_right_exist = True
                    queue.append(node.right)
                if not(node_left_exist or node_right_exist):
                    break
            else:
                height += 1
                if queue:
                    queue.append(None)
        
        return height


if __name__ == "__main__":
    root = TreeNode(3)
    root.left = TreeNode(9)
    root.right = TreeNode(20)
    root.left.left = TreeNode(1)
    root.left.right = TreeNode(2)
    root.right.left = TreeNode(15)
    root.right.right = TreeNode(7)
    Solution.minDepth(root)
