/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int pf=0;
        if(prices.size()==0||prices.size()==1)return 0;
        for(int i=0;i<prices.size();i++){
            int j=i+1;
            while(j<prices.size()&&prices[j]>prices[j-1]){
                j++;
            }
            if(j!=i+1){
                pf+=prices[j-1]-prices[i];
            }
            i=j-1;
        }
        return pf;
    }
};

