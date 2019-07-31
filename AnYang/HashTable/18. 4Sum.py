# 2019-07-22 Mon

""" 1040ms """
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

""" 76ms """
# class Solution:
#     def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
#         res = set()
#         if len(nums) < 4:
#             return []
#         Dict = {}
#         nums.sort()

#         nums2 = [nums[0]]
#         cur = nums[0]
#         cnt = 1
#         for i in range(1, len(nums)):
#             if nums[i] == cur:
#                 cnt += 1
#             else:
#                 cnt = 1
#                 cur = nums[i]
#             if cnt <= 4:
#                 nums2.append(cur)

#         nums = nums2
#         MIN = nums[0] + nums[1]
#         MAX = nums[-2] + nums[-1]
#         left = max(MIN, target - MAX)
#         right = min(MAX, target - MIN)
#         for i in range(len(nums)):
#             a = nums[i]
#             for j in range(i+1, len(nums)):
#                 b = nums[j]
#                 s = a + b
#                 if s < left:
#                     continue
#                 elif s > right:
#                     break
                
#                 if s in Dict:
#                     Dict[s].append([i, j])
#                 else:
#                     Dict[s] = [[i, j]]
#         for part_one in Dict:
#             part_two = target - part_one
#             if part_one > part_two:
#                 continue
#             if part_two not in Dict:
#                 continue
#             for pair_one in Dict[part_one]:
#                 for pair_two in Dict[part_two]:
#                     if pair_one[0] in pair_two or pair_one[1] in pair_two:
#                         continue
#                     a = nums[pair_one[0]]
#                     b = nums[pair_one[1]]
#                     c = nums[pair_two[0]]
#                     d = nums[pair_two[1]]
#                     four_sum = tuple(sorted((a,b,c,d)))
#                     res.add(four_sum)
#         return [list(four_sum) for four_sum in res]