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
    bool isSymmetricCore(TreeNode* p1, TreeNode* p2){
        if(p1==NULL && p2==NULL) return true;
        if(p1==NULL || p2==NULL) return false;
        if(p1->val != p2->val) return false;
        return isSymmetricCore(p1->left, p2->right)&&isSymmetricCore(p1->right, p2->left);
        }
    bool isSymmetric(TreeNode* root) {
        return isSymmetricCore(root, root);
    }
};
