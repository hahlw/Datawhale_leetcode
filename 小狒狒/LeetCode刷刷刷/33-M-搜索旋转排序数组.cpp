class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;
            if((nums[0] > target) ^ (nums[mid] < nums[0]) ^ (nums[mid] < target)){
                lo = mid + 1;
            }else{
                hi = mid;
            }
        }
        return lo == hi && nums[lo] == target ? lo : -1;//lo == hi这个在前面就会好！
    }
};

//就是要理清楚！
// 【旋转排序数组】， 【划分区块！！！】 【画图】
//（1）首元素和目标元素大小关系；
//（2）中点元素和首元素大小关系；
//（3）中点元素和目标元大小关系；
