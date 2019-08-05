#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        priority_queue<int, vector<int>, less<int> > pp;//xiao顶堆。
        if(input.empty()||k>input.size()||k<=0)return {};
        for (int i = 0; i < input.size();i++) {
            if(pp.size()<k){
                pp.push(input[i]);
            }
            else{
                if(input[i]<pp.top()){
                    pp.pop();
                    pp.push(input[i]);
                }
            }
        }
        vector<int> res;
        while(!pp.empty()){
            res.push_back(pp.top());
            pp.pop();
        }
        return res;
    }

};
class Solution1 {
public:
    int findKth(vector<int>&v,int lo,int hi){
        int tmp = v[lo];
        while(lo<hi){
            while(lo<hi&&v[hi]>=tmp)
                hi--;
            v[lo] = v[hi];
            while(lo<hi&&v[lo]<=tmp)
                lo++;
            v[hi] = v[lo];
        }
        v[hi] = tmp;
        return hi;
    }
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        int len = input.size();
        if(len==0||k>len||k<=0)
            return {};
        int lo = 0, hi = len - 1;
        int index = findKth(input, lo, hi);
        while(index!=(k-1)){
            if(index>k-1){
                hi = index - 1;
                index = findKth(input, lo, hi);
            }
            else{
                lo = index + 1;
                index = findKth(input, lo, hi);
            }
        }
        vector<int> res(input.begin(), input.begin() + k);
        return res; 
    }

};

int main(){
    vector<int> v{ 1, 2, 3, 4, 5, 6, 77, 8, 9 };
    Solution solu = Solution();
    vector<int> res = solu.GetLeastNumbers_Solution(v, 4);
    for(auto a :res)
        cout << a << endl;
    return 0;
}