//就是简单的赋值就好了啊！
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<vector<int>> res(r, vector<int>(c));
        if(nums.size() == 0) return res;
        int rows = nums.size(),  cols = nums[0].size();
        if( rows * cols != r * c) return nums;
        else{
            for(int i=0; i<rows*cols; i++){
                res[i/c][i%c] = nums[i/cols][i%cols];
            }
        }
        return res;
        
    }
};
