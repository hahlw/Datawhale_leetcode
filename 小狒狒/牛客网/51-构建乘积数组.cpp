class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int len = A.size();
        vector<int> B(len, 0);
        if(len>1){
            B[0] = 1;
            //先计算下三角
            for(int i=1; i<len; i++){
                B[i] = B[i-1] * A[i-1];
            }
            //再计算上三角！
            int temp = 1;
            for(int i = len-2; i>=0; i--){//注意这里是从倒数第二个开始的！
                temp *= A[i+1];
                B[i] *= temp;
            }
        }
        return B;
    }
};
