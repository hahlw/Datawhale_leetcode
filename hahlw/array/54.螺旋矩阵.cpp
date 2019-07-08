/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty())
            return {};
        int row=matrix.size();
        int len=matrix[0].size();
        vector<vector<int>>flag(row,vector<int>(len,0));
        vector<int>res;
        int i=0,j=0;
        while(j<len&&i<row&&flag[i][j]==0){
            while(j<len&&flag[i][j]==0){
                res.push_back(matrix[i][j]);
                flag[i][j]=1;
                j=j+1;
            }
            j--;
            i++;
            while(i<row&&flag[i][j]==0){
                res.push_back(matrix[i][j]);
                flag[i][j]=1;
                i=i+1;
            }
            i--;
            j--;
            while(j>=0&&flag[i][j]==0){
                res.push_back(matrix[i][j]);
                flag[i][j]=1;
                j=j-1;
            }
            j++;
            i--;
            while(i>=0&&flag[i][j]==0){
                res.push_back(matrix[i][j]);
                flag[i][j]=1;
                i=i-1;
            }
            i++;
            j++;
        }
      return res;  
    }
};

