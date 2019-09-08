class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //循环搬运n到ans
        uint32_t ans = 0;
        int i = 32;
        while(i--){
            ans<<=1;   // ans左移一位，给n的最后一位挪个窝
            ans+=n&1;  // n和1与，去除n的最后一位，放在ans的最后一位
            n>>=1;     //n右移一位，把已经挪到ans中的最后一位释放掉
        }
        return ans;
        
    }
};
//这个题是位运算，自己还不是很清楚！得好好品味一番！
