/*
n=1 A1
n=2 max(A1, A2)
n=3 max(A1, A1+A3)
···
max(f(k-2)+ Ak, f(k-1))
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int currentMoney = 0;
        int previousMoney = 0;    
        for (int i = 0; i < nums.size(); i++)    
        {       
            int temp = currentMoney;        
            currentMoney = max(currentMoney, previousMoney + nums[i]);        
            previousMoney = temp;    
        }
        return currentMoney;
    }
};
