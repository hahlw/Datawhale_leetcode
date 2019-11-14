class Solution {
public:
    int cutRope(int number) {
        //if(number == 1) return 1;
        if(number ==2) return 1;
        if(number ==3) return 2;
        if(number % 3 == 0) 
            return pow(3, number/3);
        else if(number % 3 == 1)
            return pow(3, number/3 - 1) * 4;
        else
            return pow(3, number/3)*2;
    }
};
//这个题目呢，我最能理解的就是贪心算法了！怎么说呢，感觉也不是特别巧妙的方法
//但是可以把题目做出来！
//余数这里要有自己的思考~只能是2和3！
