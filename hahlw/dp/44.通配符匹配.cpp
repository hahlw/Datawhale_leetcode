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
};

