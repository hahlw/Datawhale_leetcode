class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size(); 
        long long max1 = LONG_MIN, max2 = LONG_MIN, max3 = LONG_MIN;
        for(int i=0; i<n; i++){
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }else if( nums[i] < max1 && nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
            }else if(nums[i] > max3 && nums[i] < max2){
                max3 = nums[i];
            }
        }
        
        //处理三个数以下的情况！
        if(max3 != LONG_MIN)
            return max3;
        else
            return max1;
        
    }
};
