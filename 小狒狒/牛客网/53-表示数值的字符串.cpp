class Solution {
public:
    bool isNumeric(char* string)
    {
        bool sign = false, decimal = false, hasE = false;//分别是关于+-号， 小数点， 指数符号的！
        for(int i=0; i<strlen(string); i++){
            if(string[i] == 'e' || string[i] == 'E'){
                //e或者E不能出现在最后一位，也就是E后面要有数字！
                if( i == strlen(string) - 1) return false;
                //不能同时存在两个e
                if(hasE) return false;
                //正常情况下,检测到e，就把e的状态置为true!
                hasE = true;
            }else if( string[i] == '+' || string[i] == '-'){
                //第二次出现+-号，那么上一位必须是e!
                if(sign && string[i-1] != 'e' && string[i-1] != 'E') return false;
                //第一次出现+-号，且不在字符串开头，则也必须跟在e后面！
                if(!sign && i>0 && string[i-1] != 'e' && string[i-1] != 'E') return false;
                sign = true;
            }else if( string[i] == '.'){
                //小数点不能再E的后面
                if(hasE || decimal) return false;
                decimal = true;
            }else if( string[i] < '0' || string[i] >'9')
                return false;
        }
        return true;
    }
};
