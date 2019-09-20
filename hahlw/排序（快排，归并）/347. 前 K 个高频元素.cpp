#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int maxF=0;
        for(auto nu:nums){
            mp[nu]++;
            maxF=max(maxF,mp[nu]);
        }
        vector<vector<int>>buckets(maxF+1);
        for(auto m:mp){
            buckets[m.second].push_back(m.first);
        }
        vector<int>res;
        for(int i=maxF;i>=0;i--){
            if(!buckets[i].empty()){
                for(auto bu:buckets[i]){
                    if(k>0){
                        res.push_back(bu);
                        k--;
                    }
                    else
                        return res;
                }
            }
        }
        return res;
    }
};