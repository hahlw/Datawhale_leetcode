class Solution {
public:
    int maxArea(vector<int>& height) {
        if(height.size() <= 1) return -1;
        int left = 0, right = height.size()-1, res = 0;
        while(left < right){
            int h = min(height[left], height[right]);
            res = max(res, h * (right-left));
            if(height[left] < height[right]) 
                ++left;
            else
                --right;
        }
        return res;
    }
};
