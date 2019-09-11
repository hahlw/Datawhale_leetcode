//深搜，复杂度O(n2),超时
class Solution {
public:
    void dfs(vector<int> nums, int S, int & cnt, int cnter, int sum) {
        if(cnter == nums.size()) {
            if(sum == S)
                ++cnt;
            return ;
        }
        dfs(nums, S, cnt, cnter+1, sum+nums[cnter]);
        dfs(nums, S, cnt, cnter+1, sum-nums[cnter]);
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        int cnt = 0, sum = 0;
        dfs(nums, S, cnt, 0, sum);
        return cnt;
    }
};

//参考https://leetcode-cn.com/problems/target-sum/solution/01bei-bao-by-xeibinlin/
//背包、动态规划
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int s) {
        int sum = accumulate(nums.begin() ,nums.end(), 0);
        int ans = sum * 2 + 1; 
        if(s >= ans || s + sum >= ans) 
            return 0;
        vector<int> dp(ans);
        dp[0] = 1;
        for(auto& i:nums) 
            i = 2 * i;
        for(int i = 0; i < nums.size(); i++){
            for(int j = ans - 1; j >= nums[i]; j--){
                dp[j] += dp[j-nums[i]];
            }
        }
        return dp[sum+s]; 
    }
};
