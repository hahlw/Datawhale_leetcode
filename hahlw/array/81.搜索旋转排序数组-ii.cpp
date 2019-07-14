/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int lo = 0;
         int hi = nums.size()-1;
         while(lo <= hi){
             int mid = lo + (hi - lo)/2;
             if(nums[mid] == target)return true;
             else if(nums[mid] < target){
                 if(nums[lo]==nums[hi]&&nums[lo]!=target){
                     hi=hi-1;
                     lo=lo+1;
                 }
                 else if (nums[lo]==nums[hi]&&nums[lo]==target){
                     return true;
                 }
                 else if(nums[mid]<=nums[hi]&&target>nums[hi])hi=mid-1;
                 else lo=mid+1;
             }
             else{
                if(nums[lo]==nums[hi]&&nums[lo]!=target){
                     hi=hi-1;
                     lo=lo+1;
                 }
                 else if (nums[lo]==nums[hi]&&nums[lo]==target){
                     return true;
                 }
                 else if(nums[mid]>nums[hi]&&target<=nums[hi])lo=mid+1;
                 else hi=mid-1;
             }
         }
         return false;
    }
};

