/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */
class Solution {
public:
    //单调栈 
    /*
    遇到比栈顶元素大的元素则入栈，反之出栈，并计算当前面积。
    */
    int largestRectangleArea(vector<int>& heights) {
         stack<int>stk;
         int res = 0;
         heights.push_back(0);
         for(int i = 0;i<heights.size();i++){
            if(stk.empty()||heights[stk.top()]<heights[i]){
                stk.push(i);
            }
            else{
                int cur=stk.top();stk.pop();
                res=max(res,heights[cur]*(stk.empty()?i:(i-stk.top()-1)));
                i--;
            }
         }
         return res;
    }

    //Pruning optimize,网上的办法。
    //每次找到一个局部峰值，然后往前遍历，计算面积，更新最大面积。
     int largestRectangleArea_po(vector<int>& heights){
         int res = 0;
         for(int i =0;i<heights.size();i++){
            
            if(i+1<heights.size()&&heights[i+1]>=heights[i])continue;

            int minH=heights[i];

            for(int j=i;j>=0;j--){
                minH=min(minH,heights[j]);
                int area=minH*(i-j+1);
                res=max(res,area);
            }

         }
         return res;
     }

};

