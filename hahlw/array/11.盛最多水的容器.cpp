/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n =height.size();
        if(n==0||n==1)return 0;
        int lo=0,hi=n-1;
        int res=0;
        while(lo<hi){
            int cur=min(height[lo],height[hi]);
            res=max(res,cur*(hi-lo));
            if(height[lo]==cur){
                lo++;
            }
            else hi--;
        }
        return res;
    }
};

