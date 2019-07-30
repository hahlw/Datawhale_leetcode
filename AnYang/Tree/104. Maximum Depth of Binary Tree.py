# 2019-07-29 Mon

class Solution:
    def maxDepth(self, root):
        if root is None: 
            return 0 
        else: 
            left_D = self.maxDepth(root.left) 
            right_D = self.maxDepth(root.right) 
            return max(left_D, right_D) + 1 
