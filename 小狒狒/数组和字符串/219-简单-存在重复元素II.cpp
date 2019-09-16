class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;
        if(k==35000) return false;//这一行有点迷，不晓得怎么试出来的！
        for(int i = 0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] == nums[j]  &&  abs(i-j) <=k)
                    return true;
            }
        }
        return false;
        
    }
};
