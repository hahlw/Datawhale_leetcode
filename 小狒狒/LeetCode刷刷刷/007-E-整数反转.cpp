class Solution {
public:
    int reverse(int x) {
        int num(0);
        while(x){
            if(num < INT_MIN/10 || num > INT_MAX/10) return 0;
            num = num * 10 + x % 10;//用%来获取反转后的数字的最前面一位
            x = x / 10;//用除法抹去x的最后一位，也就是新数组的第一位！
        }
        return num;
    }
};
