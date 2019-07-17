class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int index = 2;
        for(int i=2; i<nums.size(); i++)
        {
            if(nums[i] != nums[index-2])
                nums[index++] = nums[i];
        }
        return index;
    }
};

//这个是个屡试不爽的方法，把上面的2都改成n就可以删除排序树组中的相应的元素，比如1就是保留1个，2就是保留两个，3就是保留3个相同的
//基本上算是可以的！
//代码形式和1的时候基本是一毛一样的！
//思路就是隔了几多远（就是保留几个的意思），如果还不相等，那就本地改造原数组，如果相等，那就先不动，一直遍历
//主要还是index厉害：当前数组中已经选出的非重复那么多次的元素的个数！好好体会一下！
