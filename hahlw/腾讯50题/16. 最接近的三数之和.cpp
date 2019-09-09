#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int close = INT_MAX; 
        int res = 0;
        int n = nums.size();
        if(n<=2)
            return -1;

        sort(nums.begin(), nums.end());

        for(int i = 0;i < n - 2 ; i++){
            int lo = i + 1, hi = n - 1;
            while(lo<hi){
                int cur = nums[i] + nums[lo] + nums[hi];
                if(cur==target)
                    return cur;
                else if(cur>target){
                    if(cur-target<abs(close)){
                        close = cur - target;
                        res = cur;
                    }
                    while(lo<hi&&nums[hi]==nums[hi-1])hi--;
                    hi--;
                }
                else{
                    if(target-cur<abs(close)){
                        close=target-cur;
                        res=cur;
                    }
                    
                    while(lo<hi&&nums[lo]==nums[lo+1])lo++;
                    lo++;
                }
            }
        }
        return res;
    }
};