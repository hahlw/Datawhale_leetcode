//暴力+剪纸
class Solution {
public:
    vector<string> ans;
    int N;
    void dfs(int left, int right, string has){
        if(right > left)
            return ;//左括号小于右括号
        if(left > N)
            return ;//超过N
        if(left == right && right == N){
            ans.push_back(has);
            return ;//左右都是N
        }
        dfs(left + 1, right, has + "(");
        dfs(left, right + 1, has + ")");
    }
    vector<string> generateParenthesis(int n) {
        N = n;
        if(!N)
            return {};
        dfs(0, 0, "");
        return ans;
    }
};
