/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int >res{-1,-1};
        //往前搜索：
        int lo=0,hi=nums.size()-1;
        int t=-1,e=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                t=mid;
                hi=mid-1;
            }
            else if(nums[mid]>target)hi=mid-1;
            else lo=mid+1;
        }
        if(t==-1)return res;
        //向后
        lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                e=mid;
                lo=mid+1;
            }
            else if(nums[mid]>target)hi=mid-1;
            else lo=mid+1;
        }
        res[0]=t;
        res[1]=e;
        return res;
    }
};

