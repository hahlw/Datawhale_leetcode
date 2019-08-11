#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        int twoN = 0, triN = 0, fiveN = 0;
        vector<int> res(index,0);
        res[0] = 1;
        for (int i = 1; i < index;i++){
            res[i] = min(res[twoN] * 2, res[triN] * 3, res[fiveN] * 5);
            if(res[i]==res[twoN]*2)
                twoN++;
            if(res[i]==res[triN]*3)
                triN++;
            if(res[i]==res[fiveN]*5)
                fiveN++;
        }
        return res[index - 1];
    }
};