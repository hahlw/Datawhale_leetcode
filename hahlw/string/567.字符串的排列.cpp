/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2)
    {
        int count = s1.size(), left = 0, right = 0;
        unordered_map<char, int> mp;
        for (auto ch : s1)
            mp[ch]++;
        for (; right < s2.size(); right++) {
            if (mp.find(s2[right]) != mp.end() && --mp[s2[right]] >= 0) {
                count--;
            }
            while (count == 0) {
                if (right - left + 1 == s1.size())
                    return true;
                if (mp.find(s2[left]) != mp.end()) {
                    if (++mp[s2[left]] > 0)
                        count++;
                }
                left++;
            }
        }
        return false;
    }
};
