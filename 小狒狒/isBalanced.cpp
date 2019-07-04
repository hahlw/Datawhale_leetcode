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
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        int depthL = maxDepth(root->left);
        int depthR = maxDepth(root->right);
        int res = depthL - depthR;
        if (res <-1||res>1)
            return false;
        else 
            return isBalanced(root->left)&&isBalanced(root->right);
    }
    int maxDepth(TreeNode* node){
        int depth = 9;
        if(node == NULL){
            return 0;
        }else{
            depth = max(maxDepth(node->left), maxDepth(node->right));
        }
        return depth + 1;
    }
};



