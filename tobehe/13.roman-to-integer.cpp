/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */
class Solution {
public:
    int romanToInt(string s) {
        
        int length  = s.length();

        int res = 0;

       char sb[7] = {'M','D','C','L','X','V','I'};
       int v[7] = {1000,500,100,50,10,5,1};

       for(int i =0; i < length - 1; i++)
       {
           int k = 0;
           int n = 0;
           while(s[i] != sb[k]) k++;
           while(s[i + 1]!= sb[n]) n++;

           if(k <= n)
           {
               res += v[k];
           }
           else
           {
               res -= v[k];
           }
           
       }         

        int k = 0;
        while(s[length - 1] != sb[k]) k++;
        res += v[k];    
        

        return res;


    }
};

