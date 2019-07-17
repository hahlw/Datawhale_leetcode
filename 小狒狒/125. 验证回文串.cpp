class Solution {
public:
    bool isPalindrome(string s) {
        // 双指针
        if(s.size() <= 1) return true;
        int i = 0, j = s.size() -1;
        while( i < j)
        {
            while( i<j && !isalnum(s[i]))    //排除非字母和数字的东西，比如空格和标点符号等！
                i++; 
            while( i<j && !isalnum(s[j]))
                j--;
            if(tolower(s[i++]) != tolower(s[j--])) // 大写转小写！
                return false;
        }
        return true;
    }
};
