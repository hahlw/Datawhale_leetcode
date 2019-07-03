/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */
//2019.7.3
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> res;
        bool find = false;
        for(int i = 0; i < size - 1; i++)
        {
            for(int j = i + 1; j < size; j++)
            {
                if(nums[i] + nums[j] == target)
                {
                    find = true;
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }

            if(find == true)
            {
                break;
            }
        }

        return res;
    }
};

