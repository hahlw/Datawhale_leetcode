/*
 * @lc app=leetcode id=27 lang=cpp
 *
 * [27] Remove Element
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int result = 0;
        int j =0;
        for(int i = 0; i < length; i++)
        {
            if(nums[i]!=val)
            {
                nums[j] = nums[i];
                j++;
                result++;
            }
        }

        return result;
    }
};

