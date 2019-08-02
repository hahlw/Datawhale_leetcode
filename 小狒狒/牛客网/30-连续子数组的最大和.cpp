class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        //设置两个变量一个存放最终的结果，一个存放中间的结果
        int sum = array[0], tempSum = array[0];
        //遍历，因为首先已经给上述两个变量从0，也就是第一个元素给了，
        //下面的遍历就是从第二个元素也就是下标1的位置开始
        for(int i=1; i< array.size(); i++){
            //PartI:中间变量
            //如果此刻中间临时变量是复数，那么就用当前变量初始化中间变量（继续加没意义了）
            //如果是非负的，那就把当前的array[i]继续给网上加，
            tempSum = (tempSum < 0)? array[i]:tempSum + array[i];
            //PartII:最终值
            //如果临时变量比此刻的结果变量大了，那久用这个时候临时变量来顶替结果变量
            //否则结果变量就还是结果变量！
            sum = (tempSum > sum)? tempSum: sum;
        }
        return sum;
    }
};
