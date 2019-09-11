/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */
class Solution {
public:
    bool isValid(string s) {
    
        int size = s.size();
        int i = 0;
        stack<char> c;
        char l[3] = {'(','{','['};
        char r[3] = {')','}',']'};
        while(i < size)
        {
            if(s[i]== '('||s[i]=='{'|| s[i] == '[')
            c.push(s[i]);
            else
            {

                if(c.empty())
                {
                    return false;
                }
                else
                {
                   int nl = 0; int nr = 0;
                   while(nl < 3&&s[i]!=r[nl]) nl++;
                   char t = c.top();
                   c.pop();
                   while(nr<3&&t != l[nr]) nr++;
                   if(nl != nr)
                   {
                       return false;
                   }
                    
                }
            
            }

            i++;
        }

        if(c.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
        


        

    }
};

