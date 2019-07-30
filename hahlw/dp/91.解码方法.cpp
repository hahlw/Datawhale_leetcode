/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 */
class Solution {
public:
    int numDecodings(string s) {
        if(s.empty()||s[0]=='0')return 0; 

        vector<int>dp(s.size()+1,0);

        dp[0]=1;
        //若当前位置不是零，则dp[i]+=dp[i-1]
        //如当前位置和前一个位置在10-26之间则dp[i]+=dp[i-1]

        for(int i =1;i<dp.size();i++){
            dp[i]=s[i-1]=='0'?0:dp[i-1];
            if(i>1&&(s[i-2]=='1'||(s[i-2]=='2'&&s[i-1]<='6'))){
                dp[i]+=dp[i-2];
            }
        }
        return dp[s.size()];
    }
};

