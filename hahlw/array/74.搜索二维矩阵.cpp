/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */
class Solution {
public:
    //核心思想两次二分，相比从左下角开始遍历时间复杂度要少。
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()||matrix[0].empty())return false;
        int m = matrix.size();
        int n =matrix[0].size();

        int lo=0,hi=m-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(matrix[mid][0]==target)return true;
            else if(matrix[mid][0]>target)hi=mid-1;
            else lo=mid+1;
        }
        if(hi<0)return false;//如果小于零，那么说明target比最小值还要小，即不存在。
        int row=hi;
        lo=0,hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(matrix[row][mid]==target)return true;
            else if(matrix[row][mid]>target)hi=mid-1;
            else lo=mid+1;
        }
        return false;
    }
};

