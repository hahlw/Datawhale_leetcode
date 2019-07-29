class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        //Step1:边界检查
        if(matrix.empty()) return matrix[0];
        //Step2:Settings
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> res;
        res.clear();
        int start = 0;
        //Step3:print in a 顺时针的方式
        while(cols > 2*start && rows>2*rows){
            //边界设置
            int endX = cols - 1 - start;
            int endY = rows - 1 - start;
            //(1)【从左往右】
            for( int i=start; i<=endY; i++ ){
                res.push_back(matrix[start][i]);
            }
            //(2)【从上往下】,这一步必须要保证至少两行，也就是不能还没开始就结束了
            if( start < endY){
                for(int i = start+1; i<=endY; i++){
                    res.push_back(matrix[i][endX]);
                }
            }
            //(3)【从右往左】,要保证至少两行两列
            if( start < endY && start < endX){
                for(int i = endX-1; i>=start+1; i--){
                    res.push_back(martix[endY][i]);
                }
            }
            
            //(4)【从下往上】，要保证至少三行两列
            if(start < endY+1 && start < endX){
                for(int i=endX-1; i>=start+1; i--){
                    res.push_back(matrix[i][start])
                }
            }
        
            start++;
        }
        return res;    
    }
};
