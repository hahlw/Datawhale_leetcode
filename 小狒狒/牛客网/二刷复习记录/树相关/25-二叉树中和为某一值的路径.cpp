//熟练度也蛮重要的，树这里递归用的蛮多的！
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    
    void find(TreeNode* root, int sum){
        if(root == NULL) return;
        path.push_back(root->val);
        if(!root->left && !root->right && root->val == sum)
            res.push_back(path);
        else{
            if(root->left) find(root->left, sum - root->val);
            if(root->right) find(root->right, sum - root->val);
        }
        path.pop_back();
    }
     
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        find(root, expectNumber);
        return res;
    }
};
