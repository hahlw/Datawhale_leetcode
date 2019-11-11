class Solution {
public:
    int myAtoi(string str) {
        long res = 0;
        bool isUnit = true; //True代表+   false代表-
        bool isStart = true; //表示是不是空字符，true空字符， false非空
        for(int i=0; i<str.size(); i++){
            if(str[i] == ' ' &&  isStart){
                continue;
            }else if( str[i] == '-' && isStart){
                isUnit = false;
                isStart = false;
            }else if(str[i] == '+' && isStart){
                isUnit = true;
                isStart = false;
            }else if(str[i] >= '0' && str[i] <= '9'){
                isStart = false;
                res = res * 10 + (str[i] - '0');
                if(res != int(res)){//这里注意一下！
                    if(isUnit){
                        return INT_MAX;
                    }else 
                        return INT_MIN;
                }
            }else 
                break;
        }
        if(!isUnit) res = 0 - res;
        return res;
    }
};
//做题后的一些思考：
//针对于本题，要把字符串转为整数；
//那就要考虑这些情况，也就是对应于代码张的五个判断分支:
//（1）空字符的情况||（2）前面是'+'的情况||（3）前面是'-'的情况||（4）正常的数字的情况||（5）其他的字母的情况
//================================================================
//（1）第一种情况，没啥说的，遇到了就继续往下走；
//（2）第二种情况，对于操作来说没啥，主要就是为了和'-'的情况进行区别
//（3）第三种情况，记录负号，最后好用0-res；
//（4）第四种情况，就是正常情况，直接利用res = res * 10 + (str[i] - '0')进行转换
//（5）第五种情况，就是对应与字母，那就直接break掉，逻辑还是很清晰的！
//================================================================
//在最后的时候，就是善后相关的的东西~
