class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i(0);
        for(int j=0; j<nums.size(); j++){
            if(nums[i] != nums[j])
                i++;
                nums[i] = nums[j];
        }
        return i+1;
       
    }
};
//其实思路也是很简单，把第一个元素拿出来，然后后面的开始遍历
//如果不相等的话才更新nums[i] = nums[j]且i++
//否则数组就要一直进行for循环， 一直到找出那个不相等的为止！
