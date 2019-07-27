/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty())
            return "";
        if (strs.size() == 1)
            return strs[0];
        string res = "";
        char cur = ' ';
        int i = 0;
        for (int i = 0; i < strs[0].size(); i++) {
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (i >= strs[j].size() || strs[j][i] != ch)
                    return res;
            }
            res += ch;
        }
        return res;
    }
};
