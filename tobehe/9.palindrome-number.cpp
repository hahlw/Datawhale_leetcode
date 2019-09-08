/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */
class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x < 0)
            return false;

        if(x == 0)
            return true;

        int n = 0;
        int a = x;
        
        int *array = new int[32];

        while(a > 0)
        {
            array[n] = a%10;
            a = a/10;
            n++;
        }

        for(int i = 0, j = n - 1; i<=j;i++,j--)
        {
            if(array[i]!=array[j])
            {
                return false;
            }
        }

        delete [] array;


        return true;

    }
};

