/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */
class Solution {
public:
    /*
    1.在不允许采用格外空间的条件下，我们只能在原来的数组上进行处理
    2.我们采用数组下标和数字的映射关系，也就是说本身数组就自带哈希。
    3.我们定义，当前坐标下的元素应该和当前坐标的映射为：nums[i]=i+1;
    4.当我们遇到小于1或者大于数组的长度的元素，不用采取措施，只处理区间[1,n]之间的数，遍历数组把他们放到相应的位置。
    5.最后遍历整个数组，如果元素和位置不满足哈希条件，那么当前位置就是缺失的最小整数。
    */
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            while(nums[i]<=n&&nums[i]>0&&nums[i]!=(i+1)){
                if(nums[nums[i]-1]!=nums[i])
                    swap(nums[i],nums[nums[i]-1]);
                else break;
            }
        }
        int i=0;
        for(;i<n;i++){
            if(nums[i]!=i+1)return i+1;
        }
        return n+1;
    }
};

