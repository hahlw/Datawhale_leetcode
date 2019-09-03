/*
题目要求1的个数，令F(n)表示十进制数字n转化为二进制后1的个数。
F(n) = F(n/2) + n%2
*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i = 0; i <= num; i++){
            if(i == 0){
                res.push_back(0);
            }else{  
                int current = res.at(i/2) + i%2;
                res.push_back(current);
            }
        }
        return res;
    }
};
