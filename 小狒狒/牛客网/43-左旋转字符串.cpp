【方法一】奇奇怪怪去的看不懂的方法！
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if(len==0) return "";
        n %=10;
        str += str;
        return str.substr(n,len);
    }
};

【方法二】常规的！三次反转！
class Solution {
public:
    string LeftRotateString(string str, int n) {
        int len = str.size();
        if(len == 0) return str;
        //针对移动位数比字符串还长的情况，也得考虑
        n %= len;
        //翻转第一部分
        for(int i=0, j=n-1; i<j; i++, j--) swap(str[i], str[j]);
        //翻转第二部分
        for(int i=n, j=len-1; i<j; i++, j--) swap(str[i], str[j]);
        //整体翻转
        for(int i=0, j=len-1; i<j; i++, j--) swap(str[i], str[j]);
        return str;
    }
};
