/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
 
 //方法一：创建了一个临时数组变量
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty()) return; // 边界检查
        int len=nums.size();
        if(k>nums.size()) k = k%len;//如果要挪动的次数太多就取模，
        vector<int>temp;创建一个临时变量
        for (int i=len-k;i<len;++i)
            temp.push_back(nums[i]);
        for (int j=0;j<len-k;++j)
            temp.push_back(nums[j]);
        nums=temp;
    }
};


//方法二：迭代器
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty()) return; //如果数组是空的，那就算了
        if (k>nums.size()) k = k%nums.size(); // 如果要移动的K的步数比数组长度还要长，那么久取个模，也就相当于移动了K步
        
        vector<int> temp(nums.end()-k, nums.end()); 
        nums.erase(nums.end()-k, nums.end());
        nums.insert(nums.begin(), temp.begin(), temp.end());
    }
};

