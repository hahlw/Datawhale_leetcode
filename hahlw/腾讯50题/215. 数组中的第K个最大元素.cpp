#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size()<k||k<=0)return -1;
        int lo=0,hi=nums.size()-1;
        int idx=findIdx(nums,lo,hi);
        while(idx!=k-1){
            if(idx>(k-1))
                idx=findIdx(nums,lo,idx-1);
            else
                idx=findIdx(nums,idx+1,hi);
        }
        return nums[k-1];
    }
    int findIdx(vector<int>&nums,int lo,int hi){
        int tmp=nums[lo];
        while(lo < hi){
            while(lo < hi && nums[hi] <= tmp)hi--;
            swap(nums[lo],nums[hi]);
            while(lo < hi && nums[lo] > tmp)lo++;
            swap(nums[lo],nums[hi]);      
        }
        nums[hi]=tmp; 
        return hi;
    }
};