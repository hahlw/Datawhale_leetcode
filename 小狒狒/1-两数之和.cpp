//方法一：暴力循环，时间复杂度高啊！
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        for(int i=0; i<nums.size()-1; i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i]+nums[j] == target)
                    return {i,j};
            }
        }
        return {i,j};
    }
};

//方法二：一遍哈希法，复杂度降下来了，但是我对hash并不熟悉！很气气！
//在进行迭代并将元素插入到表中的同时，我们还会回过头来检查表中是否已经存在当前元素所对应的目标元素。
//如果它存在，那我们已经找到了对应解，并立即将其返回。
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> a;//创建一对一的哈希映射
        vector<int> b(2, -1);//初始化一个大小为2，值都是-1的容器b！
        for(int i=0; i<nums.size(); i++)
        {
            if(a.count(target-nums[i])>0) //如果找到了！使用count，返回的是被查找元素的个数。如果有，返回1；否则，返回0。注意，map中不存在相同元素，所以返回值只能是1或0。
            {
                b[0] = a[target-nums[i]];
                b[1] = i;
                break;
            }
            a[nums[i]] = i; //反过来吧i对应的值放进map中，用来获取结果的下标！就是建立哈希表！i是下标,nums[i]是对应的值
        }
        
    }
};
