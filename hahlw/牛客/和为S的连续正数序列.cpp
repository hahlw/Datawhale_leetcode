#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        int lo = 1, hi = 2, cur = 3;
        while(lo<(sum+1)/2){
            if(cur==sum){
                vector<int> out = num2vec(lo, hi);
                res.push_back(out);
            }
            while(cur>sum&&lo<(sum+1)/2){
                cur -= lo;
                lo++;
                if(cur==sum){
                    vector<int>out=num2vec(lo,hi);
                    res.push_back(out);
                }
            }
            hi++;
            cur += hi;
        }
        return res;
    }
    vector<int>num2vec(int lo,int hi){
        vector<int>out;
        for (int i = lo; i <= hi;i++){
            out.push_back(i);
        }
        return out;
    }
};