class Solution {
public:
    static bool cmp(vector<int> & a, vector<int> & b) {
        return a[0] - a[1] < b[0] - b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), cmp);
        int res = 0;
        int ct = costs.size();
        for(int i = 0; i < ct; i++) {
            if(i < ct / 2)
                res += costs[i][0];
            else 
                res += costs[i][1];
        }
        return res;
    }
};
