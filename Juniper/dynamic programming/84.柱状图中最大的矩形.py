#
# @lc app=leetcode.cn id=84 lang=python3
#
# [84] 柱状图中最大的矩形
#
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        # lens = len(heights)
        # rect  = 0
        # for i in range(lens):
        #     left = i
        #     right = i 
        #     while left >0 and heights[left-1]>=heights[i]:
        #         left -=1 
        #     while right < lens-1 and heights[right+1]>=heights[i]:
        #         right +=1
        #     rect = max(rect, (right-left+1)*heights[i])
        # return rect

        if not heights:
            return 0
        lens = len(heights)
        left = [0 for i in range(lens)]
        right = [0 for i in range(lens)]
        left[0] = -1
        right[-1] = lens
        for i in range(1,lens):
            temp = i-1
            while temp >=0 and  heights[temp] >= heights[i] :
                temp = left[temp]
            left[i] = temp
            temp = lens-1-i+1
            while temp < lens and heights[temp] >= heights[lens-1-i]:
                temp = right[temp]
            right[lens-1-i] = temp
        rect = 0
        for i in range(lens):
            rect = max(rect, (right[i]-left[i]-1)*heights[i])
        return rect 


            



