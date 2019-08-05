class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < bills.size(); i++){
            if(bills[i] == 5){
                num1++;
            }else if(bills[i] == 10 && num1>0){
                num1--;
                num2++;
            }else if(bills[i] == 20 && num2 > 0 && num1 > 0){
                num2--;
                num1--;
            }else if(bills[i] == 20 && num1 >= 3){
                num1 = num1 - 3;
            }else {
                return false;
            }
        }
        return true;
    }
};
