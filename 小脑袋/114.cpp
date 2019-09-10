/**
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
    vector<TreeNode*> t;
    void modify(TreeNode *p) {
        t.push_back(p);
        if (p->left) modify(p->left);
        if (p->right) modify(p->right);
        return;
    }
    void flatten(TreeNode* root) {
        if (root) modify(root);
        for (int i = 0; i < t.size(); ++i) {
            t[i]->left = nullptr;
            t[i]->right = i + 1 < t.size() ? t[i + 1] : NULL;
        }
        return;
    }
};
