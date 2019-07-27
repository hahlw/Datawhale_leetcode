/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.size() <= 1)
            return s.size();
        vector<int> mp(256, -1);
        int left = -1, max_len = 0;
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] < left || mp[s[i]] == -1) {
                mp[s[i]] = i;
                max_len = max(max_len, i - left);
            } else {
                left = mp[s[i]];
                mp[s[i]] = i;
            }
        }
        return max_len;
    }
};
