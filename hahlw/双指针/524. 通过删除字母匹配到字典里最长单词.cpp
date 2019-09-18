#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool isSubstr(string str ,string s){
        int index1=0;
        int index2=0;
        while(index1<str.size()&&index2<s.size()){
            if(str[index1]==s[index2]){
                index1++;
                index2++;
            }
            else{
                index1++;
            }
        }
        return index2==s.size();
    }
    string findLongestWord(string s, vector<string>& d) {
        string longstring="";
        for(int i =0;i<d.size();i++){
            int l1=longstring.size(),l2=d[i].size();
            if(l1>l2||(l1==l2&&longstring<d[i]))continue;
            if(isSubstr(s,d[i])){
                longstring=d[i];
            }
        }
        return longstring;
    }
};