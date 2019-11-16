class Solution {
public:
    string intToRoman(int num) {
        vector<int> value = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> dict = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        string res;
        int i=0;
        while(num > 0 && i < dict.size()){
            if(num >= value[i]){
                res += dict[i];
                num -= value[i];
            }else{
                i++;
            }
        }
        return res;
    }
};
