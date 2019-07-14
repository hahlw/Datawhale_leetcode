/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
class Solution {
public:
    int maxProfit1(vector<int>& prices) {
        if(prices.size()==1||prices.size()==0)return 0;

        int buy1 = -prices[0], buy2 = -prices[0];
        int sell1 = 0, sell2 = 0;
        
        for(int i=0;i<prices.size();i++){
            buy1=max(buy1,-prices[i]);
            sell1=max(buy1+prices[i],sell1);
            buy2=max(buy2,sell1-prices[i]);
            sell2=max(buy2+prices[i],sell2);
        }
        return sell2;
    }
    int maxProfit(vector<int>& prices) {
         int K=3;
        vector<vector<int>>dp(K,vector<int>(prices.size(),0));
       
        for( int k=1;k<K;k++){
            for(int i=1;i<prices.size();i++){
                for(int j=1;j<=i;j++){
                    dp[k][i]=max(dp[k][i-1],dp[k-1][j-1]+prices[i]-prices[j]);
                }            
            }
        }
        return dp[2][prices.size()-1];
    }
};

