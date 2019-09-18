#include<iostream>
using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0, j = s.size() - 1; i < j;i++,j--){
            if(s[i]!=s[j]){
                return helper(s, i, j - 1) || helper(s, i + 1, j);
            }
        }
    }
    bool helper(string s,int i,int j){
        while(i<j){
            if(s[i++]!=s[j--])
                return false;
        }
        return true;
    }
};