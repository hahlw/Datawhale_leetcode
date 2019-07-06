/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt=0;
        for(int i=0;i<nums.size();i++){
            nums[i-cnt]=nums[i];
            if(nums[i]==val)cnt++;
        }
        // for(int i = 0;i<nums.size();i++){
        //     cout<<nums[i];
        // }
        return nums.size()-cnt;
    }
};

