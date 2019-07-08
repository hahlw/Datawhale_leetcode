/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
class Solution {
public:
    /*
    基本想法：结果超时，意料之中，毕竟hard.
    */
    int jump_cs(vector<int>& nums) {
        int cur_max=0;
        int n=nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        for(int i=0;i<nums.size();i++){
            cur_max=min(i+nums[i],n-1);
            //if((i+nums[i])>=(n-1))return dp[i]+1;
            for(int j=i+1;j<=cur_max;j++){
                dp[j]=min(dp[j],dp[i]+1);
            }
        }
        return dp[n-1];
    }
    /*
    贪心算法，得到一个范围之后，根据这个范围，更新下一个范围，如果当前范围和更新后的范围一致，那么就不能到达结尾
    如果我们能在一次的更新中到达最后一个节点即找到了当前最远节点。
     */
    int jump(vector<int>& nums) {
        int res=0,n=nums.size(),i=0,cur=0;
        while(cur<n-1){
            res++;
            int pre=cur;
            for(;i<=pre;i++){
                cur=max(cur,nums[i]+i);
            }
            if(pre==cur)return -1;
        }
        return res;
    }
};

