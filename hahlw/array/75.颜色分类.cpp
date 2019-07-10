/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
class Solution {
public:
    /*
    常数的空间，两次扫描。
    runtime:beats 74.98%
    memory:beats 23.56%
    */
    void sortColors_1(vector<int>& nums) {
        int cn_red=0,cn_white=0,cn_blue=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)cn_red++;
            else if(nums[i]==1)cn_white++;
            else cn_blue++;
        }
        int i =0;
        while(cn_red--)nums[i++]=0;
        while(cn_white--)nums[i++]=1;
        while(cn_blue--)nums[i++]=2;
    }
    /*
    常数的空间，一次扫描。
    runtime:beats 92.81%
    memory:beats 89.46%
    one表示应该放置1的位置，two表示放置2的位置。
    在一次遍历的时候，遇到当前位置是0那么我们交换当前位置和one位置上的元素，
    因为交换到的元素不一定是1，所以i--
    */
    void sortColors(vector<int>& nums) {
        int zero=0,two=nums.size()-1;
        for(int i = 0;i<=two;i++){
            if(nums[i]==0&&i!=zero){
                swap(nums[i--],nums[zero++]);
            }
            else if(nums[i]==2&&i!=two){
                swap(nums[i--],nums[two--]);
            }
        }
    }
};

