class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int ones = 0;
        for(long long m = 1; m<=n; m*=10){
            int a = n/m, b=n%m;
            ones += (a+8)/10 * m + (a%10==1) * (b+1);
        }
        return ones;

    }
};

还是得满动脑子的~参考：
https://www.nowcoder.com/questionTerminal/bd7f978302044eee894445e244c7eee6
