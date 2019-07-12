/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1||prices.size()==0)return 0;
        int max_pf=-1*prices[0];
        int cur_min=prices[0];
        for(int i=1;i<prices.size();i++){
            max_pf=max(prices[i]-cur_min,max_pf);
            cur_min=min(cur_min,prices[i]);
        }
        return max_pf>=0?max_pf:0;
    }
};

