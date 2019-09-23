#include<iostream>
#include<algorithm>>
#include<vector>
using namespace std; 
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.empty()){
            cout<<"0"<<endl;
            return 0;
        }
        if(intervals[0].empty()){
            cout<<"1"<<endl;
            return 0;
        }
        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0][0], end = intervals[0][1];
        int cnt = 0;
        for (int i = 1;i<intervals.size();i++){
            if(end>intervals[i][0]){
                if(end>intervals[i][1]){
                    start = intervals[i][0];
                    end = intervals[i][1]; 
                }
                cnt++;
            }
            else{
                end=intervals[i][1];
                start=intervals[i][0];
            }
        }
        return cnt;
    }
};