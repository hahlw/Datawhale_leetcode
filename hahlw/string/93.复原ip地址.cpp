/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 */
#include <iostream>
#include <string>
using namespace std;
#include <vector>
class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> res;
        helper(s, 0, "", res);
        return res;
    }
    void helper(string s, int n, string out, vector<string>& res)
    {
        if (n == 4) {
            if (s.empty())
                res.push_back(out);
            return;
        }
        for (int i = 1; i <= 3; i++) {
            if (s.size() < i)
                break;
            int val = stoi(s.substr(0, i));
            if (val > 255 || i != to_string(val).size())
                continue;
            helper(s.substr(i), n + 1, out + s.substr(0, i) + (n == 3 ? "" : "."), res);
        }
    }
};
