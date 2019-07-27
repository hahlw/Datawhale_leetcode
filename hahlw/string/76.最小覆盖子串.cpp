/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
// #include <iostream>
// #include<vector>
// #include<unordered_map>
// using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        if (t.size() > s.size())
            return "";

        unordered_map<char, int> mp;

        for (int i = 0; i < t.size(); i++) {
            if (mp.find(t[i]) != mp.end())
                mp[t[i]]++;
            else
                mp[t[i]] = 1;
        }

        int count = 0;
        int min_len = INT_MAX, left = 0, right = 0;
        string res = "";

        for (; right < s.size(); right++) {
            if (mp.find(s[right]) != mp.end()) {
                --mp[s[right]];
                if (mp[s[right]] >= 0)
                    ++count;
                while (count == t.size()) {
                    if (min_len > (right - left + 1)) {
                        min_len = right - left + 1;
                        res = s.substr(left, min_len);
                    }
                    if (mp.find(s[left]) != mp.end()) {
                        ++mp[s[left]];
                        if (mp[s[left]] > 0)
                            --count;
                    }
                    ++left;
                }
            }
        }
        return res;
    }
};
