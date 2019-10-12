class Solution {
public:
     /*三个状态的对应利润
        1.s0可买入
        2.s1可卖出
        3.s2冷冻
        maxlr=max(s0,s2);
        */
        if(prices.size()==0)return 0;
        int s0 = 0;
        int s1 = -prices[0];
        int s2 = 0;
        for(int i = 1; i < prices.size();i++){
            //不用开辟数组了，直接用变量记录上一个值
            int pre0 = s0;
            int pre1 = s1;
            int pre2 = s2;
            //☆重点！！！状态转移方程
            s0 = max(pre0, pre2);//当前可买入状态利润=max(保持原状态，从冷冻状态转换过来)
            s1 = max(pre1, pre0-prices[i]);//当前可卖出状态利润=max(保持原状态，买入物品后)
            s2 = pre1 + prices[i];//当前冷冻状态利润=可卖出状态+卖出股票
        }
        return max(s0, s2);
    }
};
