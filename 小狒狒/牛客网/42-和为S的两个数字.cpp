class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        //这道题最主要的就是要明白乘机最小就说明举例最远，乘积越大的距离越近！
        vector<int> res;
        int len = array.size();
        int i=0, j=len-1;
        while(i<j){
            if(array[i] + array[j] == sum){
                res.push_back(array[i]);
                res.push_back(array[j]);
                break;
            }
            while( i < j && array[i]+array[j] > sum) j--;
            while( i < j && array[i]+array[j] < sum) i++;
        }
        return res;
    }
};
