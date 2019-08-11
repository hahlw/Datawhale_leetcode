#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> Permutation(string str) {
        int n = str.size();
        if(n==0)
            return {};
        int* a = new int(n);
        sort(str.begin(), str.end());
        for (int i = 0; i < n;i++){
            a[i] = 0;
        }
        vector<string> res;
        helper(res, str, "", n, a);
        return res;
    }
    void helper(vector<string>&res,string&str,string cur,int len,int *a){
        if(cur.size()==len){
            res.push_back(cur);
            return;
        }
        for (int i = 0; i < len;i++){
            if(i>0&&str[i]==str[i-1]){
                if(a[i]==0&&a[i-1]==1){
                    a[i] = 1;
                    helper(res, str, cur + str[i], len, a);
                    a[i] = 0;
                }
            }
            else{
                if(a[i]==0){
                    a[i]=1;
                    helper(res, str, cur + str[i], len, a);
                    a[i] = 0;
                }
            }
        }
    }
};