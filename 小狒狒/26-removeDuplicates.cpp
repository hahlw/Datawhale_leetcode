class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    if( nums.size() == 0) return 0;
    int len = 1;  // variable to store the None-duplicated element, at first set it to 1
    for(int i = 1; i < nums.size(); i++){
        if(nums[i] != nums[len-1]){
            nums[len] = nums[i];
            ++len;
        }
    }
    return len;
    }
};
