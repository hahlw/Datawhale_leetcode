# 2019-07-22 Mon

class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        ln = len(nums)
        if ln < 4:
            return []
        res = []
        nums.sort()
        for i in range(ln-3):
            if i == 0 or nums[i] != nums[i-1]:
                for j in range(i+1, ln-2):
                    if j == i+1 or nums[j] != nums[j-1]:
                        l = j + 1
                        r = ln -1 
                        newTarget = target - nums[i] - nums[j]
                        while l < r:
                            print(l,r)
                            if nums[l] + nums[r] == newTarget:
                                res.append([nums[i], nums[j], nums[l], nums[r]])
                                while l < r and nums[l] == nums[l+1]: 
                                    l += 1
                                while l < r and nums[r] == nums[r-1]:
                                    r -= 1
                                l += 1
                                r -= 1
                            elif nums[l] + nums[r] > newTarget:
                                r -= 1
                            else:
                                l += 1
        return res
