/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
class Solution {
public:
    /*
    原则：如果当前的跳跃范围超过了n-1，则为true。
    不断更新跳跃范围。
    */
    bool canJump(vector<int>& nums) {
        int cur_max=nums[0]+0,n=nums.size(),j=0;
        if(n==0||n==1)return true;
        while(j<=cur_max){
            if(cur_max>=n-1)return true;
            cur_max=max(cur_max,nums[j]+j);
            j++;
        }
        return false;
    }
};

