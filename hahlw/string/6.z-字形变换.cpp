/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows)
    {
        if (s.size() <= numRows || numRows == 1)
            return s;
        vector<string> res(numRows, "");
        int down = 1, index = 0;
        for (int i = 0; i < s.size(); i++) {
            while (i < s.size() && down == 1 && index < numRows - 1) {
                res[index++].push_back(s[i++]);
            }
            down = 0;
            while (i < s.size() && down == 0 && index > 0) {
                res[index--].push_back(s[i++]);
            }
            down = 1;
            i--;
        }
        string con = "";
        for (auto row : res) {
            for (auto ch : row) {
                con += ch;
            }
        }
        return con;
    }
};
