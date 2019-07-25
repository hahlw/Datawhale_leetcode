//方法一：
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        for( int i = 0; i < nums.size(); i++){
            if(nums[i] != 0){
                if(k != i)
                    swap(nums[i], nums[k]);
                k++;
            }
        }
    }
};

//方法二：
//简单说就是遍历，遇到0就删除，然后在末尾补上相应个数的0，完成！主要就是这里用的是迭代器！
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int count =0;
        for(auto it = nums.begin(); it!=num.end())
        {
            if(*it==0)
            {
                it = nums.erase(it);
                count ++p
            }
            else
            {
                ++it;
            }
        }
        nums.insert(nums.end(), count, 0);
    }
};
