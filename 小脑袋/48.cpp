/*
先转换四个角，然后缩小内圈，继续转换
*/


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int ans1 = 0;
        int ans2 = matrix.size() - 1;
        int cnt = 0;
        while(ans1 < ans2) {
            int p1 = ans1;
            int p2 = ans2;
            while(p1 != ans2) {
                int temp = matrix[ans1][p1];  //左上角
                matrix[ans1][p1] = matrix[p2][ans1];  //左上角 = 左下角
                matrix[p2][ans1] = matrix[ans2][p2];  //左下角 = 右下角
                matrix[ans2][p2] = matrix[p1][ans2];  //右下角 = 右上角
                matrix[p1][ans2] = temp;              //右上角 = 左上角
                p1 += 1;
                p2 -= 1;
            }
            ans1 += 1;
            ans2 -= 1;
        }   
    }
};
