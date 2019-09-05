class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = nums[0];
        int curMaxSum = 0;
        for(int i=0; i<nums.size(); i++){
            if(curMaxSum > 0){
                curMaxSum += nums[i];
            }else{
                curMaxSum = nums[i];
            }
            res = res > curMaxSum ? res : curMaxSum;
        }
        return res;
    }
};
