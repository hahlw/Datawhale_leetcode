class Solution {
public:
    int reverse(int x) {
        int num = 0;
        while(x){   
            if (num>INT_MAX/10 || num < INT_MIN/10) return 0;     //判断是否溢出
            num = num * 10 + x % 10;   //  %用来保留原整数最后一位，
            x = x / 10;               //  /用来保留前面高位。
        }
        return num;
    }
};
