class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int i(0);
        int ans = nums[0] + nums[1] + nums[2];
        for(;i<nums.size()-2; i++){
            int start(i+1), end(nums.size()-1);
            while(start < end){
                int sum = nums[i] + nums[start] + nums[end];
                if(abs(sum-target) < abs(ans - target)){
                    ans = sum;
                }
                if(sum < target)
                    start++;
                else if(sum == target)
                    return sum;
                else
                    end--;
            }
        }
        return ans;
    }
};
//数字是排好序的！！！
//这个题呢也要像一下，自己主要还是基本上类似于三数之和的想法，固定一个进行大循环 ，然后剩下的采用双指针的方法，
//如果三个数的和直接就是目标数，那之直接返回，没商量；
//如果三数的和<目标的那就Left需要++，否则进行--
//然后这里要用个abs函数，当然不让用的话自己写也不是很难！
//弄懂了三数之和之后这个就很简单了，跟送分题一样！
