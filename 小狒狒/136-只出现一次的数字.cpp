/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 * 题目数，除了我们要的数字之外，其他都是出现两次！两次！两次！
 * 那么就要用异或，自己和自己异或等于0，所以除了结果数，其他的所有异或结果都是0，最后0和结果数异或还是结果数！
 * 异或是满足交换律和结合律的！
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
       int res = nums[0];
       for(int i=1; i<nums.size(); i++){
           res = res ^ nums[i];
       } 
       return res;
    }
};

