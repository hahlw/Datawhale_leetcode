/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
class Solution {
public:
    /*
    1.遍历两头，如果从前往后是上升趋势，则不可能接到水-->lo++，
      如果从后往前是上升趋势也不可能接到水-->hi--;
    2.比较[lo]和[hi]的大小，取其中较小的，如果是lo比较小设置为当前值，就从当前位置往后遍历直到找到比当前值大的元素停止查找，
    3.如果[lo]大于[hi]就把【hi】设为当前值，往前遍历，直到条件不满足。
    4.关键点：：：：只有在两边高中间低的时候才能节水，所以我们去当前小的值作为当前值，这样就能保证，小于当前值的这个点同时小于左边和右边。
    */
    int trap(vector<int>& height) {
        int lo=0,hi=height.size()-1;
        int res=0;
        while(lo<hi){
            while(lo<hi&&(lo+1)<height.size()&&height[lo]<height[lo+1])lo++;
            while(lo<hi&&hi>0&&height[hi]<height[hi-1])hi--;
            if(lo<hi&&height[lo]<=height[hi]){
                int cur=height[lo];
                while(lo<hi&&height[lo]<=cur){
                    res+=cur-height[lo];
                    lo++;
                }
            }
            if(lo<hi&&height[lo]>height[hi]){
                int cur=height[hi];
                while(lo<hi&&height[hi]<=cur){
                    res+=cur-height[hi];
                    hi--;
                }
            }
        }
        return res;
    }
};

