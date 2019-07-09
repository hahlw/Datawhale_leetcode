/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.empty())return digits;
        int carry=1,n=digits.size();
        for(int i=n-1;i>=0;i--){
            if(carry==0)return digits;
            int sum=digits[i]+carry;
            digits[i]=sum%10;
            carry=sum/10;
        }

        if(carry)digits.insert(digits.begin(),1);
        return digits;
    }
};

