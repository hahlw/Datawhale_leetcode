/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
class Solution {
public:

    //dp[i][j] 表示从 word1 的前i个字符转换到 word2 的前j个字符所需要的步骤。
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int> >dp(m+1,vector<int>(n+1,0));

        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=n;i++){
            dp[0][i]=i;
        }

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        return dp[m][n];
    }
};

