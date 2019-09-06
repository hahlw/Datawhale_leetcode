/*
从左到右，记录最大值，若是nums[i] < nmax，表示需要调整位置，记下位置
从右到左，记录最小值，若是nums[i] > nmin, 表示需要调整位置，记下位置
最终确定需要调整位置的范围
*/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int high = 0, low = nums.size() - 1, nmax = nums[0], nmin = nums[nums.size()-1];
        if(nums.size() <= 1)
            return 0;
        for(int i = 1; i < nums.size(); i++) {
            nmax = max(nmax, nums[i]);
            nmin = min(nmin, nums[nums.size()-1-i]);
            if(nums[i] < nmax)
                high = i;
            if(nums[nums.size()-1-i] > nmin)
                low = nums.size() - 1 - i;
        }
        return high > low ? high - low + 1 : 0;
    }
};
