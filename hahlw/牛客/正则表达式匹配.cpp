
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

/*
请实现一个函数用来匹配包括'.'和'*'的正则表达式。
模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）。 
在本题中，匹配是指字符串的所有字符匹配整个模式。
例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
*/

class Solution {
public:
    bool match(char* str, char* pattern)
    {
        int n = strlen(str);
        int m = strlen(pattern);

       
        vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
        dp[0][0] = true;

        for (int i = 1; i < m; i++) {
            if(pattern[i]=='*'&&dp[0][i-1])
                dp[0][i] = true;
        }

        for (int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                if(str[i]==pattern[j]||pattern[j]=='.')
                    dp[i+1][j+1]=dp[i][j];
                if(pattern[j]=='*'){
                    if(str[i]!=pattern[j-1]&&pattern[j-1]!='.'){
                        dp[i+1][j+1] = dp[i+1][j - 1];
                    } 
                    else{
                        dp[i + 1][j + 1] = dp[i + 1][j - 1] || dp[i + 1][j] || dp[i][j+1];                                  
                    }
                }
            }
        }
        return dp[n][m];
    }
};