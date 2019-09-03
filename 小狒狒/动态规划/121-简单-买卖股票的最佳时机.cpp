class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <=1 ) return 0;
        int min = prices[0], max = 0;//设定最小值为第一天的价格，最大利益为零
        for(int i=1; i<prices.size(); i++){
            max = max > (prices[i] - min) ? max:prices[i] - min;//max(前i-1天的最大收益，当天的价格和前i-1天中的最小价格) 即为最大利益；
            min = min < prices[i]? min : prices[i];//和当天价格相比，更新最小价格！
        }
        return max;
    }
};
