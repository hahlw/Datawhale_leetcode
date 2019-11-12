class Solution {
public:
    int maxArea(vector<int>& height) {
        int res(0);
        if(height.empty()) return res;
        int left(0), right(height.size()-1);//注意这里的right的范围！！！
        while(left<right){
            int h = min(height[left], height[right]);
            res = max(res,(right - left) * h);
            if(height[left] < height[right]){
                left++;
            }else{
                right--;
            }
        }
        return res;
    }
};
