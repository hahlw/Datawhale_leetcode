/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */
class Solution {
public:
  string countAndSay(int n) 
    {
        string r("1");
        for(int i = 2; i <= n;i++)
        {
            r = produce(r);    
        }
        return r;
    }

    string produce(string r)
    {
        string ans;
        int length = r.length();
        int i = 0;
        for(i = 0; i < length; )
        {
            char count = '0';
			int num = 0;
            while( num < length - i && r[i] == r[i + num] )
            {
                count++;
				num++;
            }
            
            ans += count;
            ans += r[i];
            i+= num;
        }
        return ans;
    }

};


