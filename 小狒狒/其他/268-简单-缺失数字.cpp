//【方法1】非常聪明的一个办法
//把现有的和本来该有的分别求和，然后相减就能得到的那一个数！注意这个题是要返回缺少的那一个数！
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int sum1 = 0;
        int sum2 = 0;
        for(int i=0; i< nums.size(); i++){
            sum1 += nums[i];
        }
        sum2 = nums.size()*(nums.size()+1)/2;
        
        res = sum2- sum1;
        return res;
    }
};

//【方法2】也是非常巧妙的一个方法是啊！！！~~~位运算的巧妙用法！
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = nums.size();
        for(int i = 0; i < nums.size(); i++){
            res ^= nums[i];
            res ^= i;
        }
        return res;
    }
};
