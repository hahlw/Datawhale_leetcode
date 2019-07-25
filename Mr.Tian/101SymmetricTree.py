class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:     
        curlayer = [root]
        nextlayer = []
        while curlayer:
            for node in curlayer:
                if node:
                    if node.left:
                        nextlayer.append(node.left)
                    else:
                        nextlayer.append(None)
                    if node.right:
                        nextlayer.append(node.right)
                    else:
                        nextlayer.append(None)
                else:
                    nextlayer.append(None)
                    nextlayer.append(None)
            
            #values = [node.val for node in nextlayer if node else -1]
            values = []
            for node in nextlayer:
                if node:
                    values.append(node.val)
                else:
                    values.append(-1)
            
            if sum(values) == -len(values):
                break
            
            if values != list(reversed(values)):
                return False
            
            curlayer = nextlayer
            nextlayer = []
        return True