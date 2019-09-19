/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */
class Solution {
public:
    int lengthOfLastWord(string s) {
        
        int res = 0;

        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] != ' ')
            {
             
                if(i!=0&&s[i-1]== ' ')
                {
                    res = 1;
                }
                else
                {
                    res++;
                }
       
            }

        }
        return res;


    }
};

