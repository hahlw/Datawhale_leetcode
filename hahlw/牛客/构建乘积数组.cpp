#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        int n =A.size();
        if(n==0)return {};
        if(n==1)return {0};
        vector<int>res(n);
        res[0] = 1;
        int tmp = 1;
        for (int i = 1; i < n;i++){
            tmp*=A[i-1];
            res[i] = tmp;
        }
        tmp = A[n - 1];
        for (int i = n - 2; i >= 0;i--){
            res[i] *= tmp;
            tmp *= A[i];
        }
        return res;
    }
};