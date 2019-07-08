/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]=i;
        }
        vector<int>res;
        for(int i=0;i<nums.size();i++){
            int t=target-nums[i];
            if(mp.count(t)&&mp[t]!=i){
                res.push_back(i);
                res.push_back(mp[t]);
                break;
            }
        }
        return res;

    }
};

