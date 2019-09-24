//右下角的边长dp[i][j] = min(dp[i+1][j+1], dp[i+1][j], dp[i][j+1])
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int x = matrix.size();
        if(x == 0)
            return 0;
        int y = matrix[0].size();
        //vector<vector<int>> dp;
        //for(int i = 0; i < dp.size(); i++)
        //    for(int j = 0; j < dp[0].size(); j++)
        //        dp[i][j] = 0;
        int dp[x+1][y+1];
        memset(dp, 0, sizeof dp);
        int len = 0;
        for(int i = 0 ; i < x; i++) {
            for(int j = 0; j < y; j++) {
                if(matrix[i][j] == '1') {
                    dp[i + 1][j + 1] = min(dp[i][j], min(dp[i+1][j], dp[i][j+1])) + 1;
                    len = max(dp[i+1][j+1], len);
                }
            }
        }
        return len * len;
    }
};
