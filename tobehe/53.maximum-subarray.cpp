/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int size = nums.size();
        
        if(size  == 0)
           return 0;

        int dp[] = new int [size];

        dp[0] = 1;

        for(int i = 1; i < size; i++)
        {
            dp[i] = Math.max(nums[i],dp[i - 1] + nums[i]);
        }

        int res = dp[0] ;

        for(int i = 0; i < size; i++)
        {
            res = Math.max(dp[i],res);
        }

        delete dp[];

        return res;






    }
};

