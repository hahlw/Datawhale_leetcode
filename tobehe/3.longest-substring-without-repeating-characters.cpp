/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int maxsize = 0;
        for(int i = 0; i < size; i++)
        {
            unordered_map<char,int> m;
            int tmp = 0;
            for(int j = i;j < size;j++)
            {
                if(m.find(s[j]) == m.end())
                {
                    m.insert(make_pair(s[j],0));
                    tmp++;
                }
                else
                {
                    /* code */
                    break;
                }

            }

            if(tmp > maxsize)
            {
                maxsize = tmp;
            }
        }
        
        return maxsize;

    }

};

