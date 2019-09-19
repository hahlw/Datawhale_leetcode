class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0 || s.size() == 1) 
            return s;
        if(s.size() == 2 && s[0] == s[1])
            return s;
        int start(0), end(0);
        int maxLen(0);
        for(int i=0; i<s.size(); i++){
            int len1 = findSameLength(s, i, i);
            int len2 = findSameLength(s, i, i+1);
            if(maxLen < max(len1, len2)){
                maxLen = max(len1, len2);
                start = i- (maxLen - 1) / 2;
                end = i + maxLen / 2;
            }
        }
        return s.substr(start, end - start +1);
    }
    
    int findSameLength(string &s, int left, int right){
        while(left >= 0 && right < s.size() && s.at(left) == s.at(right)){
            left--, right++;
        }
        return right-left-1;
    }
};
