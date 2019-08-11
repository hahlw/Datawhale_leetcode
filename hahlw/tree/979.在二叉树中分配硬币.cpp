/*
 * @lc app=leetcode.cn id=979 lang=cpp
 *
 * [979] 在二叉树中分配硬币
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
    int ans;
    int distributeCoins(TreeNode* root)
    {
        ans = 0;
        dfs(root);
        return ans;
    }
    //返回每一个节点的负载量。
    int dfs(TreeNode* node)
    {
        if (!node) {
            return 0;
        }
        int L = dfs(node->left);
        int R = dfs(node->right);
        ans += abs(L) + abs(R);
        return node->val + L + R - 1;
    }
};
