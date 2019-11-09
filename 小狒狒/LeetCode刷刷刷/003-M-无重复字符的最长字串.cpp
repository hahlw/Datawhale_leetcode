class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //维护的窗口的大小[)
        int start(0), end(0), length(0), res(0);//这种的复制方式更加的面向对象！
        int sSize = s.size();
        while(end < sSize){
            char tempChar = s[end];
            //在以有的窗口中寻找，找到了就要重新设置窗口
            for(int index = start; index<end; index++){
                if(s[index] == tempChar){
                    start = index + 1;
                    length  = end - start;
                    break;
                }
            }
            //没找到重读的就继续把窗口扩大，然后长度也扩大
            end++;
            length++;
            res = max(length, res);//维护一个最大的窗口——无重复字符的最长字串的窗口的大小！
        }
        return res;
    }
};
