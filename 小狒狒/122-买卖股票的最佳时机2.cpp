class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        if(prices.size() == 0) return0;
        for(  int i = 1; i < nums.size(); i++){
            if(nums[i-1] < nums[i] ){
                profit += nums[i] - nums[i-1];
            }
        }
        return profit;
    }
};
