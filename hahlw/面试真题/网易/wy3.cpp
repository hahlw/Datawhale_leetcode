#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> solve(vector<vector<int>>& timeSet) {
        vector<int> resSet;
        for (int i = 0; i < timeSet.size(); ++i) {
            int time = 0;
            int water = 0;
            int m = timeSet[i][0];
            int t = timeSet[i][1];
            int t1 = timeSet[i][3];
            int t2 = timeSet[i][5];
            vector<int> m1(2, 0);
            m1[0] = timeSet[i][2];
            vector<int> m2(2, 0);
            m2[0] = -timeSet[i][4];
            while (time < t) {
                int temp = m1[(time / t1) % 2] + m2[(time / t2) % 2];
                water += temp;
                if (water < 0) water = 0;
                if (water > m)  water = m;
                ++time;
            }
            resSet.push_back(water);
        }
        return resSet;
    }
};

int main() {
    int n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    int a, b, c, d, e, f;
    vector<vector<int>> timeSet;
    for (int i = n; i > 0; --i) {
        cin >> a >> b >> c >> d >> e >> f;
        vector<int> one;
        one.push_back(a);
        one.push_back(b);
        one.push_back(c);
        one.push_back(d);
        one.push_back(e);
        one.push_back(f);
        timeSet.push_back(one);
    }
    vector<int> resSet = Solution().solve(timeSet);
    for (int i = 0; i < resSet.size(); ++i)
        cout << resSet[i] << endl;
    return 0;
}