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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0)
            return NULL;
        int i = 0;
        for(; i < inorder.size(); i++) {
            if(inorder[i] == preorder[0])
                break;
        }
        TreeNode* root= new TreeNode(preorder[0]);
        vector<int> preleft(preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> preright(preorder.begin() + i + 1, preorder.end());
        vector<int> inleft(inorder.begin(), inorder.begin() + i);
        vector<int> inright(inorder.begin() + i + 1, inorder.end());
        root->left = buildTree(preleft, inleft);
        root->right = buildTree(preright, inright);
        return root;
    }
};
