#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    //指数幂
    double Power(double base, int exponent)
    {
        double tmp = base;
        double res = 1;
        int f = exponent < 0 ? -1 : 1;
        exponent = abs(exponent);
        while (exponent) {
            if (exponent & 1) {
                res *= tmp;
            }
            exponent >>= 1;
            tmp *= tmp;
        }
        return f == -1 ? 1 / res : res;
    }
};

int main() { return 0; }
