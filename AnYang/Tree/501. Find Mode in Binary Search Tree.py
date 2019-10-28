# 2019-10-28 Mon

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:return []
        stack=[root]
        dic={}
        while stack:
            node=stack.pop()
            dic[node.val]=dic.get(node.val,0)+1
            if node.left:
                stack.append(node.left)
            if node.right:
                stack.append(node.right)
        max_val=max(dic.values())
        result=[]
        for key in dic.keys():
            if dic[key]==max_val:
                result.append(key)
        return result