class Solution {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = array.size(), cols = array[0].size();
        if(rows > 0 && cols > 0 && !array.empty()){
            int row = 0, col = cols-1;
            while(row<rows && col >= 0){
                if(array[row][col] == target)
                    return true;
                else if(array[row][col] < target)
                    row++;
                else
                    col--;
            }
        }
        return false;
    }
};
//一定要思考啊！！！
