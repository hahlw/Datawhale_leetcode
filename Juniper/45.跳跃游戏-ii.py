#
# @lc app=leetcode.cn id=45 lang=python3
#
# [45] 跳跃游戏 II
#
class Solution:
    def jump(self, nums):        
        lens = len(nums)
        dis = 0 
        cnt = 0   
        bound = 0
        for i in range(lens-1):          
            dis=max(dis, nums[i]+i)
            if bound == i:
                cnt = cnt +1
                bound = dis           
        return cnt 

      
        # lens = len(nums)     
        # cnt = 0    
        # while lens :
        #     for i in range(lens-1):
        #         if nums[i] >= lens- i :
        #             cnt = cnt+1
        #             lens = i
        #             break
        # return cnt 
        

