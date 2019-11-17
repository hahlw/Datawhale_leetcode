class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size() < 4) return {};
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        set<vector<int>> aa;//用于去重
        for(int i=0; i<nums.size()-3; i++){
            if(nums[i] >= target && target >0) break;
            for(int j=i+1; j<nums.size() - 2; j++){
                int left(j+1), right(nums.size()-1);
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if(sum < target)
                        left++;
                    else if(sum== target){
                        vector<int> temp{nums[i], nums[j], nums[left],  nums[right]};
                        aa.insert(temp);
                        left++;
                        right--;
                    }else
                        right--;
          
                }
            }
        }   
        for(auto c: aa){
            res.push_back(c);
        }
        return res;
    }
};
//基本上和三数之和，最接近三个数之和的思路一直，固定一个或者两个，剩下的用双指针来控制！
//主要还是代码的实现上需要注意一些细节上的东西了！
