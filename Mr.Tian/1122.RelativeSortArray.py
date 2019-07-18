class Solution:
    def relativeSortArray(self, arr1: List[int], arr2: List[int]) -> List[int]:
        common = {}
        diff = []
        ans = []
        
        for item in arr2:
            if item not in common:
                common[item] = 0
        
        for item in arr1:
            if item in common:
                common[item] += 1
            else:
                diff.append(item)
        
        diff.sort()
        
        for num in common.keys():
            ans.extend([num] * common[num])
        
        return ans + diff