class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        int i(nums.size() - 2), j(nums.size() - 1);
        //Step1:
        while(i >= 0 && nums[i+1] <= nums[i])
            i--;
        //Step2:
        if( i>=0 ){
            while(j>=0 && nums[j] <= nums[i])
                j--;
            swap(nums[i], nums[j]);
        }
        //Step3:
        reverse(nums.begin() + i +1, nums.end());
        
    }
};
//基本思路：
//Step1:倒着找第一个 【顺序对】 ————————————i；
//Step2:在找到的顺序对合法的情况下，倒着寻找第一个大于上面i对应的数，并且交换
//Step3:把i之后的所有数组从新排序变成升序，从而达到刚好是   下一个  的目的！
