
//一个数字单个，其他两个

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=nums[0];
        for(int i=1;i<nums.size();i++){
            res^=nums[i];      
        }
        return res;
    }
};


//一个数字单个，然后其他是三个。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(auto n:nums){
                sum+=(n>>i)&1;
            }
            res|=(sum%3)<<i;
        }
        return res;

    }
};


//存在两个单一数字
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff=0;
        for(auto n:nums)diff^=n;
        int flag=1;
        while(flag){
            if(flag&diff)break;
            flag<<=1;
        }
        vector<int>res(2,0);
        for(auto n:nums){
            if(n&flag)res[0]^=n;
            else res[1]^=n;
        }
        return res;
    }
};
