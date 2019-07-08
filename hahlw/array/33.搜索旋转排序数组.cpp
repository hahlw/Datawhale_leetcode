/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo=0,hi=nums.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target)return mid;
            else if(nums[mid]>target){
                /*
                1,常规二分法-->hi=mid-1;
                2,非常规,mid在前半段-->nums[mid]>nums[hi],目标值在后半段-->target<=nums[hi]，lo=mid+1;
                 */
                if(nums[mid]>nums[hi]&&target<=nums[hi])lo=mid+1;
                else hi=mid-1;
            }
            else{
                /*
                1,常规二分法-->lo=mid+1;
                2,非常规，mid在后半段-->nums[mid]<nums[hi]，目标值在前半段-->target>nums[hi],hi=mid-1;
                */
                if(nums[mid]<nums[hi]&&target>nums[hi])hi=mid-1;
                else lo=mid+1;
            }
        }
        return -1;
    }
};

