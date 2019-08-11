#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.size()==1)
            return true;
        if(sequence.empty())
            return false;
        int tmp = sequence.back();
        int n = sequence.size();
        int i = 0;
        while(i<n-1){
            if(sequence[i]>tmp)
                break;
            i++;
        }
        vector<int> left(sequence.begin(), sequence.begin() + i);
        vector<int> right(sequence.begin() + i, sequence.end() - 1);
        for(auto n :left){
            if(n>tmp)
                return false;
        }
        for(auto n:right){
            if(n<tmp)
                return false;
        }
        if(!left.empty()&&!right.empty())
            return VerifySquenceOfBST(left) && VerifySquenceOfBST(right);
        else if(!left.empty())
            return VerifySquenceOfBST(left);
        else
            return VerifySquenceOfBST(right);
    }
};