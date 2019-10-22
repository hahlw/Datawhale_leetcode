LCP1:
class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        return (guess[0] == answer[0]) + (guess[1] == answer[1]) + (guess[2] == answer[2]);
    }
};

LCP2:
//对题目中列示进行通分找规律
class Solution {
public:
    vector<int> fraction(vector<int>& cont) {
       
        if(cont.size() == 1) 
            return {cont[0], 1};
       // int len = 
        int up = cont[cont.size() - 2] * cont[cont.size() - 1] + 1;
        int down = cont[cont.size() - 1];
        if(cont.size() > 2)
        {
            for(int i = cont.size() - 2; i > 0; --i) {
                int temp;
                temp = up;
                up = down + up * cont[i - 1];
                down = temp;
            }
        }
        return {up, down};
    }
};
