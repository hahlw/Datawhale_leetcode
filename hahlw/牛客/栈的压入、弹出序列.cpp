#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV)
    {
        stack<int> stk;
        int k = 0;
        int n=popV.size();
        for (int i = 0; i < n;i++){
            int tmp = popV[i];
            if(k<n && stk.empty()){
                stk.push(pushV[k++]);
            }
            while(k<n&&stk.top()!=tmp){
                stk.push(pushV[k++]);
            }
            if(k<n&&stk.top()==tmp){
                stk.pop();
            }
            else
                return false;
        }
    }
};