class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=1;
        int maj = nums[0];
        for(int i=1; i<nums.size(); i++){
            if(maj == nums[i]) count++;
            else{
                count--;
                if(count == 0) maj = nums[i+1];
            }
        }
        return maj;
    }
};
//求众数，就是一个数组中出现次数最大的那个数！
//从第一个来，然后往后遍历，如果遇到想通的数，count++, 如果不相同就count--,一直到count到0，那就换一个继续！
//这样总会找到的！
