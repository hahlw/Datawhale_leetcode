/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */
class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.size();
        int len2 = b.size();

        string res;
        int carry = 0;
        int i = len1 - 1;
        int j = len2 - 1;

        while( carry > 0 || i>=0||j >= 0)
        {
            int num1 = 0;
            int num2 = 0;
            if(i >=0)
            {
                num1 = a[i--]-'0';
            }
            if(j >= 0)
            {
                num2 = b[j--] - '0';
            }

            int sum = num1 + num2 +carry;
            res.push_back(sum%2 + '0');
            carry = sum/2;
        }

        reverse(res.begin(),res.end());

        return res;

    }
};

