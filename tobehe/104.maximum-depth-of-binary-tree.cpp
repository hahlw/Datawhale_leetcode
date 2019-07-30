/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */
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
    int maxDepth(TreeNode* root) {
        int depth = 0;
        
        TreeNode *p = root;

        if(root == NULL)
            return 0;
        
        int left = maxDepth(p->left);
        int right = maxDepth(p->right);

        depth += left > right?left:right;
        depth++;
        
        return depth;

    }
};

