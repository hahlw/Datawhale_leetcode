//动态规划
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.empty())
            return true;
        vector<bool> dp(s.size(), false);
        for(int i = 0; i < s.size(); i++)
        {
            for(string& word: wordDict)
            {
                int size = word.size();
                if(i - size >= -1 && word == s.substr(i - size + 1, size) && (i - size == -1 || dp[i - size]))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[s.size() - 1];
    }
};
