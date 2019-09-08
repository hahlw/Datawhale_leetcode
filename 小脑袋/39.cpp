class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        if(candidates.empty())
            return res;
        vector<int> out;
        sort(candidates.begin(), candidates.end());
        DFS(candidates, out, res, target, INT_MIN);
        return res;
    }
    void DFS(vector<int>& candidates, vector<int> &out,vector<vector<int> > &res,int target,int front)
    {
        for(int i = 0; i < candidates.size(); i++){
            out.push_back(candidates[i]);
            if(candidates[i] < front) {
                out.pop_back();
                    continue;
            }
            if(target - candidates[i] == 0)
                res.push_back(out);
            else if(target - candidates[i] < 0) {
                out.pop_back();
                continue;
            }
            else
                DFS(candidates,out,res,target - candidates[i],candidates[i]);
            out.pop_back();
        }
    }
};
