/*
 * @lc app=leetcode id=7 lang=cpp
 *
 * [7] Reverse Integer
 */
class Solution {
public:
    int reverse(int x) {
        int a = x;
        if(a == -2147483648)
        {
            return 0;
        }

        int sign = 1;
        if(x < 0)
        {
            a = -x;  
            sign = -1; 
        }

        int re = 0;

        while(a>0)
        {
            int b = a%10;
            a = a/10;
            if(re > (2147483648 -1)/10||(re == (2147483648 -1)/10&& b > ((2147483648 - 1)%10)))
            {
                return 0;
            }
            re = re*10 + b;
        }

        return sign*re;

        
    }

};

