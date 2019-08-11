#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        vector<int> mp(256, 0);
        int n = str.size();
        for(int i = 0; i < n;i++){
            mp[str[i]]++;
        }
        for (int i = 0; i < n;i++){
            if(mp[str[i]]==1)
                return i;
        }
        return -1;
    }
};