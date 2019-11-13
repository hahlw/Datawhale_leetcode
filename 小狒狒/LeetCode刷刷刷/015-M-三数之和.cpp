class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size() && nums[i]<=0; i++){
            // if(nums[i]>0) break;//对于已经排好序的，那么你第一个都已经大于零了，后面的就不用看了
            if(i !=0 && nums[i] == nums[i-1]) continue;//对于连着重复的元素，那么就没必要再考虑一次了；
            int left(i+1), right(nums.size()-1);
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < 0)
                    left++;
                else if(sum > 0)
                    right--;
                else if(sum==0){
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                    while(left<right && nums[left] == nums[left-1]) left++;
                }
            }
        }
        return res;
    }
};
