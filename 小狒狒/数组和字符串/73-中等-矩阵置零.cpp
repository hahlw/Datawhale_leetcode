class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();//矩阵的行数
        if (m == 0) return ;
        int n = matrix[0].size();//矩阵的列数
        bool row0 = false, col0 = false;//标志位
        //逐个元素扫描，
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0) row0 = true;
                    if (j == 0) col0 = true;
                    matrix[0][j] = matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[0][j] == 0 || matrix[i][0] == 0) 
                    matrix[i][j] = 0;
            }
        }
        if (col0)
            for (int i = 0; i < m; i++) matrix[i][0] = 0;
        if (row0)
            for (int j = 0; j < n; j++) matrix[0][j] = 0;
    }
};
