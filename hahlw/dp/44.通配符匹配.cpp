/*
 * @lc app=leetcode.cn id=44 lang=cpp
 *
 * [44] 通配符匹配
 */
class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0, iStar = -1, jStar = -1;
        while(i<s.size()){
            if(s[i]==p[j]||p[j]=='?'){
                i++;
                j++;
            }
            else if(p[j]=='*'){
                iStar=i;
                jStar=j;
                j++;
            }else if(iStar>=0){//如果不相等j=jStar+1,i++;
                i=++iStar;
                j=jStar+1;
            }
            else return false;
        }
        while (j < p.size() && p[j] == '*') ++j;
        return j == p.size();
    }
    //DP
    bool isMatch(string s, string p) {
        if(p.empty())return s.empty();
        int n = s.size();
        int m = p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));
        dp[0][0]=true;
        for(int i = 0;i < m;i++){
            if(p[i]=='*'&&dp[0][i]){
                dp[0][i+1]=true;
            }
        }//连续的*,匹配空串
        
        for(int i = 0;i < n;i++){
            for(int j =0;j < m;j++){
                if(s[i]==p[j]||p[j]=='?')
                    dp[i+1][j+1]=dp[i][j];
                if(p[j]=='*'){//'*'可匹配任意字符，匹配空，匹配多个(如果匹配前i-1,那么前i个也可以匹配（多一个无所谓）)
                    dp[i+1][j+1]=dp[i+1][j]||dp[i][j+1];
                }
            }
        }
        return dp[n][m];
    }
};

