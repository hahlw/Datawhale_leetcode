class Solution {
public:
    int myAtoi(string str) {
        long result = 0;
        bool isUint = true;//
        bool isStart = true;//true表示空字符，false表示找到组织了
        for(int i=0; i< str.size(); i++){
            if(str[i] == ' ' && isStart)            //Step1: 首先寻找非空字符
                continue;
            else if(str[i] == '-' && isStart){      //Step2: 找到非空后先检查符号
                isStart = false;
                isUint = false;
            }else if(str[i] == '+' && isStart){     //但是问题是正负号,便于对超级大的数进行判断！
                isStart = false;
                isUint = true;
            }else if(str[i]>='0' && str[i] <='9'){  //Step3: 判断当前字符串是否合法（是否是真的数字！）
                isStart = false;
                result = result*10 + (str[i] - '0'); //转换成int类型！
                if(result != (int)result){          //Step4: 特殊情况处理，如果超过了，正数的话返回INT_MAX,负数的话返回INT_MIN
                    if(isUint) return INT_MAX;
                    else return INT_MIN;
                }
            }else{                                  //Step5: 以上情况都不满足的话那就之际break好了！
                break;
            }
        }
        if( !isUint ) result = 0 - result;
        
        return result;
    }
};
