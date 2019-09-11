#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>res(nums.size(),1);
        int tmp = nums[0];
        for(int i=1;i<n;i++){
            res[i]=tmp;
            tmp*=nums[i];
        }
        tmp=1;
        for(int j = n-2;j>=0;j--){
            tmp*=nums[j+1];
            res[j]*=tmp;
        }
        return res;
    }
};