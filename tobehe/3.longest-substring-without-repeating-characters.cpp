/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int length = s.length();

        if(length <=0)
        {
            return 0;
        }

        int i,j, k, r = 1;
        for(i = 0; i < length; i++)
        {
            int c =1;
            bool isdif = true;
            for(j = i + 1;j < length;j++)
            {
                 for(k = i; k < j;k++)
                 {
                     if(s[j] == s[k])
                     {
                         isdif = false;
                        break;  
                     }
                 }
                 if(!isdif)
                 {
                     break;
                 }
            }

            c = (j - i);

            if(c > r)
            {
                r = c;
            }

        }

        return r;

    }
};

