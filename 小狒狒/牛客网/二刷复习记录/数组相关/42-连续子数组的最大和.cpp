class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        int sum = array[0], tempSum = array[0];
        for(int i=1; i<array.size(); i++){
            tempSum = tempSum<0? array[i] : tempSum + array[i];
            sum = max(sum, tempSum);
        }
        return sum;
    }
};
//典型的动态规划！！！
