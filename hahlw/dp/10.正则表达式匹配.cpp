/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 */
class Solution {
public:
    bool isMatch(string s, string p) {
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
};

