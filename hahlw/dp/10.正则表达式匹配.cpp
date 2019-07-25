/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
class Solution {
public:
    //递归
    bool isMatch_DG(string s, string p) {
        if(p.empty())return s.empty();

        if(p.size()==1)return s.size()==1&&(s[0]==p[0]||p[0]=='.');

        if(p[1]=='*'){
            if(!s.empty()&&(p[0]==s[0]||p[0]=='.')){
                return isMatch(s,p.substr(2))||isMatch(s.substr(1),p);
                       //||isMatch(s.sbustr(1),p.substr(2))=s.subtrs(1),p-->s,p.substr(2)
            }
            else if(!s.empty())return isMatch(s,p.substr(2));
            else {
                while(s.empty())
                    return isMatch(s,p.substr(2));
            }
        }
        else{
            if(s.empty())return false;
            return (s[0]==p[0]||p[0]=='.')&&(isMatch(s.substr(1),p.substr(1)));
        }
        return false;
    }

    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        vector<vector<bool>>dp(n+1,vector<bool>(m+1,false));

        dp[0][0]=true;

        for(int i=0;i<m;i++){
            if(p[i]=='*'&&dp[0][i-1]){
                dp[0][i+1]=true;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
               if(s[i]==p[j]||p[j]=='.'){
                   dp[i+1][j+1]=dp[i][j];
               }
               if(p[j]=='*'){
                   if(p[j-1]!=s[i]&&p[j-1]!='.'){
                       dp[i+1][j+1]=dp[i+1][j-1];
                   }
                   else{
                       dp[i+1][j+1]=(dp[i+1][j]||dp[i+1][j-1]||dp[i][j+1]);//match one ,zero,multiple
                   }
               } 
            }
        }
        return dp[n][m];

    }

};

