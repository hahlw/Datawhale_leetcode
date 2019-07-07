/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>cur;
        sort(candidates.begin(),candidates.end());
        unordered_map<int,int>mp;
        for(int i=0;i<candidates.size();i++){
            mp[i]=1;
        }
        helper(candidates,res,cur,0,target,0,mp);
        return res;
    }
    /*
    1.原始数组排序
    2.给每一个位置做一个是否使用的标记。
    3.如果当前位置和前一个位置的元素相同，并且前一个位置标记为未使用，那么就应该跳过当前位置。
        设想在我们排好序的数组中，如果我们前一个位置未使用，那么也就是在前一个位置的元素已经在递归中使用了，那么当前位置的元素如果再次使用就会产生重复元素。
    */
    void helper(vector<int>& candidates, vector<vector<int>>& res,vector<int>& cur,int ct,int target,int start,unordered_map<int,int>&mp){
        if(ct==target){
            res.push_back(cur);
            return ;
        }
        if(ct>target)return ;
        //允许重复。
        for(int i=start;i<candidates.size();i++){
            if(i>0&&candidates[i]==candidates[i-1]){
                if(mp[i-1]==1)
                    continue;
            }
            cur.push_back(candidates[i]);
            mp[i]=0;
            helper(candidates,res,cur,ct+candidates[i],target,i+1,mp);
            cur.pop_back();
            mp[i]=1;
        }
    }
};

