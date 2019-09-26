//用二进制还是很easy的
class Solution {
public:
    int findComplement(int num) {
        int temp = num;
        int ans = 0;
        while(temp > 0) {
            temp >>= 1;
            ans = (ans << 1) + 1;
        }
        return num ^ ans;
    }
};
