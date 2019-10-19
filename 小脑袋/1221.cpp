class Solution {
public:
    int balancedStringSplit(string s) {
        int sum = 0, contL = 0, contR = 0;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'L')
                contL++;
            else
                contR++;
            if(contL == contR)
                sum++;
        }
        return sum;
    }
};
