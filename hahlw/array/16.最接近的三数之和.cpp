/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff_min=INT_MAX;
        int close=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
            int lo=i+1,hi=n-1;
            while(lo<hi){
                int cur=nums[lo]+nums[hi]+nums[i];
                int diff=abs(cur-target);
                if(diff<diff_min){
                    diff_min=diff;
                    close=cur;
                }
                else if(cur<target)lo++;
                else hi--;
            }
        }
        return close;
    }
};

