class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int res(0);
        for(int i=0; i<nums.size(); i++){
            if(nums[i] != val){
                nums[res] = nums[i];
                res++;
            }
        }
        return res;
    }
};
//这个题其实和之前那个非常的像
//只不过 这个数组是没有排序的，删除的是指定大小的数字！
//那么就是还是一次遍历，如果遇到等于特定值的，i++直接跳过!如果不是指定值的，那就把这个值拷贝记录下来！
//同时更新res++以及i++;
