class Solution {
public:
    int rectCover(int number) {
        if(number <= 2) return number;
        int coverMinusTwo = 1;
        int coverMinusOne = 2;
        int coverN = 0;
        for( int i = 3; i<=number; i++){
            coverN = coverMinusTwo + coverMinusOne;
            coverMinusTwo = coverMinusOne;
            coverMinusOne = coverN;
        }
        return coverN;
    }
};
//需要注意的就是 前面的要思路清楚！从哪里开始，这里就是从第三个开始，和原始的斐波那契相比是没有0的！所以从3开始！把问题彻底想明白！
