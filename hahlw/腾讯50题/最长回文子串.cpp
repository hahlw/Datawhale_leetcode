#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.size();
        if(len<=1)return s;
        int max_len=1,lo=0;
        vector<vector<int>>dp(s.size(),vector<int>(s.size(),0));
        for(int i=0;i<s.size();i++){
            for(int j=0;j<i;j++){
                if(s[i]==s[j]){
                    if(i-j<=2||dp[j+1][i-1]==1)
                        dp[j][i]=1;
                }
                if(dp[j][i]==1&&max_len<(i-j+1)){
                    max_len=i-j+1;
                    lo=j;
                }
            }
            dp[i][i]=1;
        }
        return s.substr(lo,max_len);
    }
};