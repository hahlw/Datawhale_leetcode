class Solution:
    def pathInZigZagTree(self, label):
        
        # only odd layer
        def helper(layer, label):
            path = [0] * layer
            path[0], path[-1] = label, 1
            
            if layer % 2 == 1:
                num = label
                index = 0
                
                # odd layer
                while index < layer:
                    path[index] = num
                    num = int(num / 4)
                    index += 2
                    
                # even layer
                for index in range(1, layer, 2):
                    label_sum = 2**(layer - index) + 2**(layer - index - 1) - 1
                    path[index] = label_sum - int(path[index-1] / 2)
                    
            return path[::-1]
        
        # calculate layer
        layer = 1
        while label > 2**layer - 1:
            layer += 1
        
        # odd / even
        if layer % 2 == 1:
            return helper(layer, label)
        else:
            # first num
            num = 2**(layer - 1) + 2**(layer - 1 - 1) - 1 - int(label / 2)
            path = helper(layer-1, num)
            path.append(label)
            return path