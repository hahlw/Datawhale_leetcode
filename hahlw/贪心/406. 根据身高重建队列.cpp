#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // 先排序
        // [7,0], [7,1], [6,1], [5,0], [5,2], [4,4]
        
        // 再一个一个插入。
        // [7,0]
        // [7,0], [7,1]
        // [7,0], [6,1], [7,1]
        // [5,0], [7,0], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [7,1]
        // [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] > b[0]) return true;
            if (a[0] == b[0] && a[1] < b[1]) return true;
            return false;
        });
        
        vector<vector<int>> res;
        for (auto e : people) {
            res.insert(res.begin() + e[1], e);
        }
        return res;
    }
};
