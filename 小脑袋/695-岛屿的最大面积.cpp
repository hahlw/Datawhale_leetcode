class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> res = grid;
        int row = grid.size(), col = grid[0].size();
        if(row <= 0)
            return 0;
        if(col <= 0)
            return 0;
        int mx = 0;
        for(int i = 0; i < row; i++){
            for(int j =  0; j < col; j++){
                int count = 0;
                if(res[i][j] > 0) //未访问过,且是岛屿
                    dfs(res, i, j, count);
                if(mx < count)
                    mx = count;
            }
        }
        return mx;        
    }
    //从(m,n)位置开始DFS
    void dfs(vector<vector<int>>& grid, int m, int n, int& count){
        int row = grid.size(), col = grid[0].size();
        if(m < 0 || n < 0 || m >= row || n >= col)
            return ;
        if(grid[m][n]<= 0){
            grid[m][n] = -1; //代表已访问
            return;
        }
        grid[m][n] = -1;
        count++;
        dfs(grid, m - 1, n, count);
        dfs(grid, m + 1, n, count);
        dfs(grid, m, n - 1, count);
        dfs(grid, m, n + 1, count);
    }
};
