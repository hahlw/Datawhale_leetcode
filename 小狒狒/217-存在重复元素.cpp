/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */
 //【方法一：】
class Solution {
    //  static bool cmp(const int &a, const int &b){
    //     return a < b;
    // }
public:
    bool containsDuplicate(vector<int>& nums) {
        if(nums.size()<=1) return false;
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
    }
};

//如果不加上面的cmp的话，时间复杂度就高，但是究其内容我还是不懂，缺乏数据机构和算法的支持真的惨！加油加油！
//加上之后就可以打败90%左右了！

//【方法二】set的特性
//class Solution {
//public:
//    bool containsDuplicate(vector<int>& nums) {
//        set<int> Set(nums.begin(),nums.end());
//        return Set.size()!=nums.size();
//    }
//};
