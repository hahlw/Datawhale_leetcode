# 2019-09-26 Thu

class Solution:
    def binaryTreePaths(self, root: TreeNode) -> List[str]:      
        paths = []
        if not root:
            return []
        stack = [(root, [])]
        while stack:
            node, path = stack.pop()
            if node.left:
                stack.append((node.left, path + [node.val]))
            if node.right:
                stack.append((node.right, path + [node.val]))
            if not node.left and not node.right:
                paths.append(path + [node.val])
                
        return list(map(lambda s: "->".join(map(str, s)), paths))