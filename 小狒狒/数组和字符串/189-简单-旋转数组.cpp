/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return;
        int len=nums.size();
        if(k>nums.size()) k = k%len;
        vector<int>temp;
        for (int i=len-k;i<len;++i)
            temp.push_back(nums[i]);
        for (int j=0;j<len-k;++j)
            temp.push_back(nums[j]);
        nums=temp;
    }
};

//还有个方法比较好，三次反转！

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.size() == 0) return;
        k = k % nums.size();        
        reverse(nums.begin(), nums.end()-k );
        reverse(nums.end()-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};


