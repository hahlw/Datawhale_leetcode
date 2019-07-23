
//【方法一】3ms——归纳分析
class Solution {
public:
    int jumpFloorII(int number) {
        if(number <2 ){
            return number;
        }else{
            return  2 * jumpFloorII(number-1);
        }

    }
};

//【方法二】3ms——位运算
class Solution {
public:
    int jumpFloorII(int number) {
        int a = 1;
        return a<<(number-1);
    }
};
//要看清问题的本质，可以归纳一下找到规律之后再进行解题！！！
