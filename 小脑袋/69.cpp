class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //记录行和列数
        int n = grid[0].size();
        int m = grid.size();
        //第一行的和
        for(int i = 1; i < n; i++)
            grid[0][i] = grid[0][i-1] + grid[0][i];
        //第一列的和
        for(int i = 1; i < m; i++)
            grid[i][0] = grid[i-1][0] + grid[i][0];
        //选择较小的
        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                grid[i][j] = min(grid[i-1][j] + grid[i][j], grid[i][j-1]+grid[i][j]);
        return grid[m-1][n-1];
    }
};
