//461.汉明距离   异或
class Solution {
public:
    int hammingDistance(int x, int y) {
        int cnt = 0;
        int res = x ^ y;
        while(res)
        {
            if(res & 1 == 1)
            {
                cnt++;
            }
            res = res >> 1;
        }
        return cnt;
    }
};
//617.合并二叉树
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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1 == NULL)
            return t2;
        if(t2 == NULL)
            return t1;
        t1->val += t2->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};
//226.翻转二叉树  递归
//递归
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        TreeNode* right = invertTree(root->right);
        TreeNode* left = invertTree(root->left);
        root->right = left;
        root->left = right;
        return root;
    }
};
