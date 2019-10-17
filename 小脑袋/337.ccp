/**
讲真，不太会
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    pair<int,int> dp(TreeNode* root)
    {
        if(!root)
            return make_pair(0,0);
        auto l = dp(root->left);
        auto r = dp(root->right);
        return make_pair(max(l.first, l.second) + max(r.first, r.second), root->val + l.first + r.first);
    }
    int rob(TreeNode* root) {
        pair<int,int> res = dp(root);
        return max(res.first, res.second);
    }
};
