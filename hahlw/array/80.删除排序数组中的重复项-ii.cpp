/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */
class Solution {
public:
    /*
    因为这个数组是有序的，即相同的数字都是连续的
    设置两个指针，慢指针pre，快指针cur
    因为要求最多是重复两次，我们设置一个表示count，当慢指针和快指针的值相同，此时count-1，如果不相同count=1；
    count=0表示我们当前数组中这个数已经出现两次了，如果再出现就需要过滤掉。
    采用同时移动快慢指针的方法，来过滤掉多余的数
    如果快慢指针的值不相同或者相同但是count！=0，那么我们把快指针的数赋值给慢指针
    如果快慢指针的值相同而且count=0此时我们只移动快指针，慢指针不动，count还是原来的零。
    */
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)return nums.size();
        int pre=0,cur=1,count=1,n=nums.size();
        while(cur<n){
            if(nums[cur]==nums[pre]&&count==0)++cur;
            else{
                if(nums[cur]==nums[pre])count--;
                else count=1;
                nums[++pre]=nums[cur++];
            } 
        }
        return pre+1;
    }
};

