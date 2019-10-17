# 2019-10-17 Thu

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        if root:
            queue = [root]
            
        else:
            queue = []
        result = []
        while queue:
            layer = [kid.val for kid in queue]
            result.append(sum(layer)/len(layer))
            mid = queue
            queue = []
            for i in mid:
                if i.left:
                    queue.append(i.left)
                if i.right:
                    queue.append(i.right)
                    
            
        return result