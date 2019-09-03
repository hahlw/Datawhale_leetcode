//如果利用递归，肯定超时间！大量的重复计算！
//所以！从下往上去计算！
class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) return n;
        int climbMinusOne = 2;
        int climbMinusTwo = 1;
        int climbN = 0;
        for(int i = 3; i<=n; i++){
            climbN = climbMinusTwo + climbMinusOne;
            climbMinusTwo = climbMinusOne;
            climbMinusOne = climbN;
        }
        return climbN;
    }
};
