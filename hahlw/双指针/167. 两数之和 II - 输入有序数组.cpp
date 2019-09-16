#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        if(n<=1)return {};
        int lo=0,hi=n-1;
        while(lo<hi){
            int cur=numbers[lo]+numbers[hi];
            if(cur==target){
                return {lo+1,hi+1};
            }
            if(cur<target)lo++;
            else hi--;
        }
        return {};
    }
};