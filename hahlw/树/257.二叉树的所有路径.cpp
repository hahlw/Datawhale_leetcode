/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>res;
        findPath(root,res,"");
        return res;
    }
    void findPath(TreeNode*root,vector<string>&res,string cur){
        if(!root)return ;
        string a;
        stringstream ss;
        ss<<root->val;
        ss>>a;
        if(root->left == nullptr && root->right == nullptr){
            cur+=a;
            res.push_back(cur);
            return ;
        }
        cur+=a;
        cur+="->";
        if(root->left){
            findPath(root->left,res,cur);
        }
        if(root->right){
            findPath(root->right,res,cur);
        }
    }
};

