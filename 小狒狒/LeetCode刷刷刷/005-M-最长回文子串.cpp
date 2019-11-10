class Solution {
public:
    string longestPalindrome(string s) {
        //Case1:空的或者只有一个的，就是回文，直接返回
        if(s.size() == 0 || s.size() == 1) 
            return s;
        //Case2:如果只有两个相等的元素，也是回文字符串，直接返回；
        if(s.size() == 2 && s[0] == s[1])
            return s;
        
        //Case3:一般情况
        //--Step1:先初始化变量，
        int start(0), end(0);//start和end记录回文子串的起始位置
        int maxLen(0);//maxLen用来记录回文子串的长度
        //--Step2:遍历寻找，【中心拓展法】
        //--在findSameLength中实现
        for(int i=0; i<s.size(); i++){
            int len1 = findSameLength(s, i, i);//奇数aba
            int len2 = findSameLength(s, i, i+1);//偶数abba
            //最大的疑惑就是这里了！！！start 和end的赋值！！！好好理解！
            if(maxLen < max(len1, len2)){
                maxLen = max(len1, len2);
                //长度往两边拓展一般！
                start = i- (maxLen - 1) / 2;
                end = i + maxLen / 2;
            }
        }
        return s.substr(start, end-start+1);//这里真的是费解~~
    }
    
    int findSameLength(string &s, int left, int right){
        //如果两个位置的元素值相等，那就往两边扩展
        while(left >= 0 && right < s.size() && s.at(left) == s.at(right)){
            left--, right++;
        }
        //然后返回此时子串的长度，因为相等的时候已经移动了一步，所以得到的值多1，因此再减掉1
        return right-left-1;
    }
};
