/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>>dp(s.size(),vector<bool>(s.size()));
        if(s.size()==0||s.size()==1)return s;
        int res=1;
        int lo=0,hi=0;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<i;j++){
                if(s[i]==s[j]&&(i-j<2||dp[i-1][j+1])){
                    dp[i][j]=true;
                }
                if(dp[i][j]&&(i-j+1)>res){
                    res=i-j+1;
                    lo=j;
                    hi=i;
                }
            }
            dp[i][i]=true;
        }
        cout<<lo<<res;
        return s.substr(lo,res);
    }
    
};

