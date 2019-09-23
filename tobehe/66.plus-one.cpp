/*
 * @lc app=leetcode id=66 lang=cpp
 *
 * [66] Plus One
 */
class Solution {
public:
     vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        vector<int> res;
        stack<int> tmp;
        int flag = 0;

        int num = (flag + digits[size - 1] + 1) %10;
        flag = (flag + digits[size - 1] + 1)/10;
        tmp.push(num);
         
        for(int i = size - 2; i >= 0; i-- )
        {
            num = (flag + digits[i]) %10;
            flag = (flag + digits[i] )/10;
            tmp.push(num);
        }
        if(flag)
        {
            tmp.push(flag);
        }

        int size1 = tmp.size();
        for(int i = 0; i < size1; i++)
        {
            int t = tmp.top();
            tmp.pop();
            res.push_back(t);
        }

        return res;
    }
};

