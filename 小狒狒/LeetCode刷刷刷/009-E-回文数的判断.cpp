class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x % 10 == 0 && x != 0) return false;
        int reversed(0);
        while(x > reversed){                        //循环的判断
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }
        return reversed == x || reversed / 10 == x;//奇偶数
    }
};
//蛮简单的，主要需要注意两点：
//(1)循环的结束的判断
//(2)最后的对比要记得分清奇偶数。
