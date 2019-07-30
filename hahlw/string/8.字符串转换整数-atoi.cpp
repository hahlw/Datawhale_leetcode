/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */
#include <iostream>
#include <limits.h>
using namespace std;
class Solution {
public:
    int myAtoi(string str)
    {
        int i = 0;
        int res = 0;
        while (i < str.size() && str[i] == ' ')
            i++;
        if (i == str.size() || (str[i] != '-' && str[i] != '+') && (str[i] > '9' || str[i] < '0'))
            return 0;
        int flag = str[i] == '-' ? -1 : 1;
        if (str[i] == '-' || str[i] == '+')
            i++;
        while (i < str.size()) {
            if (str[i] < '0' || str[i] > '9')
                break;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && str[i] > '7'))
                return flag == 1 ? INT_MAX : INT_MIN;
            res = res * 10 + (str[i] - '0');
            i++;
        }
        return flag * res;
    }
};
