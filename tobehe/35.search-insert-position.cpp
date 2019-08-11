/*
 * @lc app=leetcode id=35 lang=cpp
 *
 * [35] Search Insert Position
 */
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int length = nums.size();

        int p0 = 0;
        int p1 = length - 1;

        while(p0 < p1)
        {
            int m = (p0 + p1 + 1)/2;
            if(target == nums[m])
                return m;
            else if(target < nums[m])
            {
                p1 = m - 1;
            }
            else
            {
                p0 = m + 1;
            }
        }   

        return target <= nums[p1]?p1:p1+1;
    }
};

