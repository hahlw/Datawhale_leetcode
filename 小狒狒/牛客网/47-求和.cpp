//有很多种方法的！但是我都不会啊！怎么办我也不知道！，先掌握一个吧！
class Solution {
public:
    int Sum_Solution(int n) {
        int ans = n;
        //当n>0时，执行sum+=Sum_Solution(n-1)，实现递归计算Sum_Solution(n)。
        //n=0时候就直接结束递归了！时间复杂度N
        ans && (ans += Sum_Solution(n-1));
        return ans;
    }
};
