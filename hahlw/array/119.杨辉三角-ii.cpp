/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>res(rowIndex+1,0);
        res[0]=1;
        for(int i=1;i<=rowIndex;i++){
            for(int j=i;j>0;j--){
                res[j]+=res[j-1];
            }
        }
        return res;
    }
};

