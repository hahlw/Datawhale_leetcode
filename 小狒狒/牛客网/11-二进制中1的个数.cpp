【方法一：常规】——3ms
//思路，需要移动的并不是给定的数组，而是这个我们的flag！
//这样就可以避免当给定数组是负数的时候右移造成的不必要的麻烦！
class Solution {
public:
     int  NumberOf1(int n) {
        int count = 0;
        unsigned int flag = 1;
        while(flag){
            if( n&flag )
                count++;
            flag = flag << 1;
        }
        return count;
     }
};
【方法二：惊喜】——3ms
//二进制一个数减去1，那么1的位置就变为0,1后面的所有位就变成1；
//比如1100 减去 1 后就称为 1011
//这个时候1100再和1011与，那就得到了1000==>得到了一个1
//再给1000减去1就是0111，再和1000与
//得到0000，这个时候相当于又得到了一个===>得到第二个1
//count计数相应的增加就好了！
//所以规律就是，有几个1，就能够这样与几次直到！n不满足循环条件
class Solution {
public:
     int  NumberOf1(int n) {
        int count = 0;
        while(n){
            count++;
            n = n & (n-1);
        }
        return count;
     }
};
