/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>cur;
        helper(nums,res,cur,0);
        return res;
    }
    void helper(vector<int>&nums,vector<vector<int>>&res,vector<int>&cur,int start){
        if(start>=nums.size()){
            res.push_back(cur);
            return ;
        }
        res.push_back(cur);
        for(int i=start;i<nums.size();i++){
            cur.push_back(nums[i]);
            helper(nums,res,cur,i+1);
            cur.pop_back();
        }
    }
};

