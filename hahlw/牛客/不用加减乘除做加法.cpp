#include<iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        int carry = 0, sum = num1;
        while (num2) {
            sum = num1^num2;
            carry = (num1&num2) << 1;
            num2 = carry;
            num1 = sum;
        }
        return sum;
    }
};