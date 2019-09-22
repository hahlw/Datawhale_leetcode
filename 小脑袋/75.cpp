class Solution {
public:
    void sortColors(vector<int>& nums) {
        int index = -1;
        int left = 0, right = nums.size();
        
        while(left < right){
            if(nums[left] == 0){
                swap(nums[++index], nums[left++]);
            }
            else if(nums[left] == 2){
                swap(nums[--right], nums[left]);
            }
            else
                left++;
        }
        return ;
    }
};
