class Solution {
public:
   bool valid(vector<int> &special_single, vector<int> &needs){
        for(int i=0;i<needs.size();i++){
            if(special_single[i]>needs[i]) return false;
        }
        return true;
    }
int shoppingOffers(vector<int> &price, 
        vector<vector<int>> &special, vector<int> &needs) {
        int min_money = 0;
        for(int i=0;i<needs.size();i++){
            min_money += price[i] * needs[i];
        }
        for(int i=0;i<special.size();i++){
            if(valid(special[i],needs)){
                vector<int> new_needs; 
                for(int j=0;j<needs.size();j++)
                    new_needs.push_back(needs[j]-special[i][j]); 
           int money_tmp = shoppingOffers(price,special,new_needs) +
               special[i].back();
           min_money = min(min_money,money_tmp); 
            }
        }
        return min_money;
    }
};
