/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 */
class Solution {
public:
    //写的比较丑，不够简练。O(m+n)
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.empty())return ;
        int m = matrix.size();
        if(matrix[0].empty())return ;
        int n = matrix[0].size();
        set<int>row;
        set<int>col;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(int i=0;i<m;i++){
            if(row.find(i)!=row.end()){
                for(int j=0;j<n;j++){
                    matrix[i][j]=0;
                }
            }
            
        }
        for(int i=0;i<n;i++){
            if(col.find(i)!=col.end()){
                for(int j=0;j<m;j++){
                    matrix[j][i]=0;
                }
            }
        }
    }
    /*
    先扫描第一行第一列，如果有0，则将各自的flag设置为true
    然后扫描除去第一行第一列的整个数组，如果有0，则将对应的第一行和第一列的数字赋0
    再次遍历除去第一行第一列的整个数组，如果对应的第一行和第一列的数字有一个为0，则将当前值赋0
    最后根据第一行第一列的flag来更新第一行第一列
     */
    void setZeroes_o1(vector<vector<int>>&matrix){
        if(matrix.empty())return ;
        int m = matrix.size();
        if(matrix[0].empty())return ;
        int n = matrix[0].size();

        bool rowZero=false,colZero=false;
        for(int i=0;i<m;i++){
            if(matrix[i][0]==0)colZero=true;
        }
        for(int j=0;j<n;j++){
            if(matrix[0][j]==0)rowZero=true;
        }

        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(matrix[0][j]==0||matrix[i][0]==0){
                    matrix[i][j]=0;
                }
            }
        }
        if(rowZero){
            for(int i =0;i<n;i++){
                matrix[0][i]=0;
            }
        }
        if(colZero){
            for(int i =0;i<m;i++){
                matrix[i][0]=0;
            }
        }
    }
};

