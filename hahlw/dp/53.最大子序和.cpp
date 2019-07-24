/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int cur = 0;
        for(int i=0;i<nums.size();i++){
            if(cur<=0)cur=0;
            cur+=nums[i];
            sum=max(sum,cur);
        }
        return sum;
    }
};

