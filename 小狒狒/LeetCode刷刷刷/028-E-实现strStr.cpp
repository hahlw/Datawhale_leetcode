class Solution {
public:
    int strStr(string haystack, string needle) {
        int res(0);
        if( needle.size() == 0) return res;
        res = haystack.find(needle);
        return res;
        
    }
};

//【方法二：】
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size() == 0) return 0;
        int i(0), j(0);
        while(haystack[i] != '\0' && needle[j] != '\0'){
            if(haystack[i] == needle[j]){
                i++;
                j++;
            }else{
                i = i - j +1;
                j = 0;
            }     
        }
        if(needle[j] == '\0')
            return i-j;
        return -1;
    }
};
//第一种方法就是调用库函数
//第二种的话就是可以理解为暴力方法，比较简单！多思考几次！
