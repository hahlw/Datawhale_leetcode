/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
    int maxProfit2(vector<int>& prices) {
        if(prices.size()<=1)return 0;
        int K=3;
        vector<vector<int>>dp(K,vector<int>(prices.size(),0));
       
        for( int k=1;k<K;k++){
            int max_pf=-prices[0];
            for(int i=1;i<prices.size();i++){
                //int max_pf=prices[i]-prices[0]+dp[k-1][j];//dp[k-1][j]=0;
                //int max_pf=-prices[0];
                // for(int j=1;j<=i;j++){
                //     max_pf=max(max_pf,dp[k-1][j-1]-prices[j]);
                // }
                // dp[k][i]=max(max_pf+prices[i],dp[k][i-1]);      
                max_pf=max(max_pf,dp[k-1][i-1]-prices[i]);
                dp[k][i]=max(max_pf+prices[i],dp[k][i-1]);        
            }
        }
        return dp[2][prices.size()-1];
    }

    int maxProfit1(vector<int>& prices) {
        if(prices.size()<=1)return 0;
        int K=3;
        vector<vector<int>>dp(K,vector<int>(prices.size(),0));
        for( int k=1;k<K;k++){
           // int max_pf=-prices[0];
            for(int i=1;i<prices.size();i++){
                //int max_pf=prices[i]-prices[0]+dp[k-1][j];//dp[k-1][j]=0;
                int max_pf=-prices[0];
                for(int j=1;j<=i;j++){
                    max_pf=max(max_pf,dp[k-1][j-1]-prices[j]);
                }
                dp[k][i]=max(max_pf+prices[i],dp[k][i-1]);         
            }
        }
        return dp[2][prices.size()-1];
    }
};

