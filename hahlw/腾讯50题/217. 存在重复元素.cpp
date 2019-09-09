#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto n :nums)
        {
            if(mp.find(n)!=mp.end())return true;
            else{
                mp[n]=1;
            }
        }
        return false;
    }
};