/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void find(TreeNode* pRoot, int sum){
        if(pRoot == NULL) return;
        path.push_back(pRoot->val);
        if(!pRoot->left && !pRoot->right && sum == pRoot->val){
            res.push_back(path);
        }else{
            if(pRoot->left){
                find(pRoot->left, sum - pRoot->val);
            }
            if(pRoot->right){
                find(pRoot->right, sum - pRoot-val);
            }
        }    
        path.pop_back();
    }
    
    vector<vector<int>> FindPath(TreeNode* root, int expectNumber){
        find(root, expectNumber);
        return res;
    }    
};
