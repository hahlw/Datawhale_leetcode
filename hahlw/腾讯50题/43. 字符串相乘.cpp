#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int m = num1.size(), n = num2.size();
        if(num1[0]=='0'||num2[0]=='0'){
            return "0";
        }
        vector<int> tmp(n + m, 0);
        for (int i = n-1; i >=0;i--){
            for (int j = m-1; j >= 0;j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1, sum = mul + tmp[p2];
                tmp[p1] += sum / 10;
                tmp[p2] = sum % 10;
            }
        }
        string res = "";
        for(int t :tmp){
            if(!res.empty()||t!=0)
                res.push_back(t + '0');
        }
        return res;
    }
};