class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int small  = 1, big = 2;
        //只要小的比大的小就一直继续！
        while(big > small){
            //Step1:设置当前的和，
            int curSum = (small+big) *(big -small+1) / 2;
            //如果当前值比目标值小，那么就把所选区间的big扩大，增加
            if(curSum < sum)
                big++;
            //如果相等，那就先保存到临时变量就好！然后小的增加！
            if(curSum==sum){
                vector<int> temp;
                for(int i=small; i<=big; i++){
                    temp.push_back(i);
                }
                res.push_back(temp);
                small++;
            }
            //如果当前值已经比目标值大了，那就把最小值换掉！
            if(curSum > sum)
                small++;
        }
        return res;
    }
};
