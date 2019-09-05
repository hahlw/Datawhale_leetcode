class Solution {
public:
    bool match(char* str, char* pattern)
    {
        //Case1:两个都是空的，匹配！
        if( *str == '\0' && *pattern == '\0' )
            return true;
        //Case2:字符串非空，模式为空的，不匹配！
        if( *str != '\0' && *pattern == '\0')
            return false;
        //下面根据pattern的两种情况进行判断！
        //Case1:首先是模式的第二位不是*的情况，比较简单！
        if( *(pattern+1) != '*'){
            //匹配上了，往后走！
            if(*str == *pattern || *str != '\0' && *pattern == '.')
                return match(str+1, pattern+1);
            //没匹配上，结束！
            else
                return false;
        }
        //Case2:模式的第二位如果是*的话，问题就复杂了！
        else{
            //*匹配上了，且匹配了一个（*起作用一次，字符串往后走，模式不变）或者多个字符（*起作用多次，移动两位，跳过*），！
            if(*str == *pattern ||(*str != '\0' && *pattern == '.'))
                return match(str+1, pattern)|| match(str, pattern+2);
            //*没匹配上！模式往后走两位，跳过*，可以理解把*本身当做0来看！
            else
                return match(str, pattern+2);
        }
    }
};
