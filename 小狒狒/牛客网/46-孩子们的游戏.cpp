//【方法一】数学——循环
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1) return -1;
        int last = 0;
        for(int i=2; i<=n; i++){
            last = (last+m) % i;
        }
        return last;
    }
};
//【方法二】数学-递归
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        if(n<1 || m<1) return -1;
        if(n==0) return 0;
        return (LastRemaining_Solution(n-1,m)+m)%n;
    }
};
