#include<iostream>
#include<limits.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int flag = x > 0 ? 1 : -1;
        if(x==INT_MAX||x==INT_MIN)
            return 0;

        x = abs(x);

        int res = 0;
        while(x){
            int sec = x % 10;
            if(res>INT_MAX/10)
                return 0;
            else if(flag==1&&res==INT_MAX/10&&sec>7)
                return 0;
            else if(flag==-1&&res==INT_MAX/10&&sec>8)
                return 0;
            res = res * 10 + sec;
        }
        return res;
    }
};