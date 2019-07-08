/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if(a[0]<b[0]||(a[0]==b[0]&&a[1]<b[1]))return true;
        else return false;
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        for (int i=0;i<intervals.size();i++){
             int start = intervals[i][0];
             int end = intervals[i][1];
             int j = i + 1;
             while(j<intervals.size()){
                if(end>=intervals[j][0]){//a[1]==b[0]
                    end=max(intervals[j][1],end);//a[0]<b[0]&&a[1]>b[1]
                    j++;
                }
                else break;
             }
             if(j!=i+1){
                 intervals.erase(intervals.begin()+i,intervals.begin()+j);
                 intervals.insert(intervals.begin()+i,{start,end});
             }
        }
        return intervals;
    }
};

