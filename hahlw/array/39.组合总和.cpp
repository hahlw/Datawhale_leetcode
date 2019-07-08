/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>cur;
        helper(candidates,res,cur,0,target,0);
        return res;
    }
    void helper(vector<int>&candidates,vector<vector<int>>&res,vector<int>&cur,int ct,int target,int start){
        if(ct==target){
            res.push_back(cur);
            return ;
        }
        if(ct>target)return ;
        //允许重复。
        for(int i=start;i<candidates.size();i++){
            cur.push_back(candidates[i]);
            helper(candidates,res,cur,ct+candidates[i],target,i);
            cur.pop_back();
        }
        //不允许重复。
        /*
        for(int i=start;i<candidates.size();i++){
            cur.push_back(candidates[i]);
            helper(candidates,res,cur,ct+candidates[i],target,i+1);
            cur.pop_back();
        }
         */
        
    }
};

