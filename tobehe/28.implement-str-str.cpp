/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 */
class Solution {
public:
    int strStr(string haystack, string needle) {
        int length1 = haystack.size();
        int length2 = needle.size();

        if(length2 == 0)
        {
            return 0;
        }

        int j ,k;
        for(int i = 0; i < length1; i++)
        {
            
            for(j = 0, k = i; j < length2; j++,k++)
            {
                if(haystack[k]!= needle[j])
                {
                    break;
                }
            }

            if(j == length2)
            {
                return i;
            }

        }

        return -1;


    }
};

