class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()) return "";
        //用第一个字符串来控制
        for(int i=0; i<str[0].size(); i++)
        {
            //用每个strs里面的str和第一个来匹配
            for(int j=0; j<str.size(); j++)
            {
                //只要遇到不一样，就把之前一样的输出
                if(str[j][i] != str[0][i]) return str[0].substr(0,i);
            }
        }
        //最牛逼的情况就是和整个第一个都一样！
        return strs[0];
    }
};
