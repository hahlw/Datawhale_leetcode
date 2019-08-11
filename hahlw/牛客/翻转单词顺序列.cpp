#include<iostream>
#include<algorithm>
using namespace std;
#include<string>

class Solution {
public:
    string ReverseSentence(string str) {
        int i = 0, j = 0, n = str.size();
        reverse(str.begin(), str.end());
        while(i<n){
            while(i<n&&str[i]==' ')
                i++, j++;
            while(j<n&&str[j]!=' ')
                j++;
            reverse(str.begin() + i, str.begin() + j);
            i = j;
        }
        return str;
    }
};
