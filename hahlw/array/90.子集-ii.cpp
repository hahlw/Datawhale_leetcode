/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=1;
        }    
        vector<vector<int>> res;
        vector<int>cur;
        sort(nums.begin(),nums.end());
        helper(nums,res,cur,0,mp);
        return res;
    }

    void helper(vector<int>&nums,vector<vector<int>>&res,vector<int>&cur,
                int start,unordered_map<int,int>&mp){
        if(start>=nums.size()){
            res.push_back(cur);
            return ;
        }
        res.push_back(cur);
        for(int i=start;i<nums.size();i++){
            if(mp[nums[i]]==1&&i>0&&nums[i]==nums[i-1])
                continue;
            cur.push_back(nums[i]);
            mp[nums[i]]=0;
            helper(nums,res,cur,i+1,mp);
            cur.pop_back();
            mp[nums[i]]=1;
        }
    }
};


