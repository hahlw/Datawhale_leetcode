#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        long cnt = 0;
        for (int i = 1; i <= n;i*=10){
            int fir = n / i;
            int sec = n % i;
            //fir+8有效的处理了两种情况：1：如果大于2，+8以后进1，
            //如果==0，加8和不加一样。
            cnt += (fir + 8) / 10 * i +
                  (fir % 10 == 1) * (sec + 1);//当前位是不是1.
        }
        return cnt;
    }
};