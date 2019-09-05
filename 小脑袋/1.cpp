/*
建立一个哈希表，将每一个值与目标值相减，
为正在表内写入且为1，为负则写为0，每次
都要在哈希表中查看是否有与之相加和为目
标值的数。
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        map <int, int> HashMap;
        for(int i = 0 ; i < nums.size(); i++) {
            int temp = target - nums[i];
            if(HashMap.count(temp)) {
                res = vector<int>({HashMap[temp], i});
                break;
            }
            HashMap[nums[i]] = i;
        }
        return res;
    }
};
