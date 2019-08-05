#include<iostream>
#include<string.h>
using namespace std;
/*
请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。 
但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 */
class Solution {
public:
	bool isNumeric(char* str)
	{
        bool sign = false, hase=false, hasdot = false;
        if(str==nullptr)
            return false;
        int len = strlen(str);
        for (int i = 0; i < len;i++){
            if(str[i]=='e'||str[i]=='E'){
                if(hase)
                    return false;
                else
                    hase = true;
            }
            else if(str[i]=='+'||str[i]=='-'){
                if(sign&&(str[i-1]=='e'||str[i-1]=='E'))
                    return false;
                if(!sign&&i>0&&(str[i-1]=='e'||str[i-1]=='E'))
                    return false;

                sign = true;
            }
            else if(str[i]=='.'){
                if(hase||hasdot)
                    return false;
                hasdot = true;
            }
            else if (str[i]<'0'&&str[i]>'9')
                return false;
        }
        return true;
    }
};