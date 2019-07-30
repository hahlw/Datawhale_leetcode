/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 */
class Solution {
public:
    string countAndSay(int n) {
        vector<string>res(n,"");
        res[0]="1";
        int i=1;
        while(i<n){
            for(int j=0;j<res[i-1].size();j++){
                int cnt=1;
                auto c=res[i-1][j];
                int k=j+1;
                for(k;k<res[i-1].size();k++){
                    if(res[i-1][k]==c)cnt++;
                    else break;
                }
                res[i].push_back(cnt+'0');
                res[i].push_back(c);
                j=k-1;
            }
            i++;
        }
        return res[n-1];
    }
};

