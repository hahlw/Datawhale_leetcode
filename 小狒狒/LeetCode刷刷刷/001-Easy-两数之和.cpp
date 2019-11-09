class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> record;
        for(int i=0; i<nums.size(); i++){
            int temp = target - nums[i];
            if(record.find(temp) != record.end()){
                res.push_back(i);
                res.push_back(record[temp]);
                break;
            }else{
                record[nums[i]] = i;
            }
        }
        return res;
        
    }
};
//这里主要就是用unordered_map来实现的，为什么要用呢？因为unordered_map是基于散列表实现的，所以查找起来是非常方便的，就很快！
//然后这里find()函数的话如果找到了目标，就返回的就是这个目标对应的下标或者说是指针或者迭代器吧~如果没找到就一直返回了unordered_map的最后一个
//找到的情况下就吧结果放回res中，没有的话就把现有的放进record中！
//当然最直接的方法还是暴力法了！也不是不行！
