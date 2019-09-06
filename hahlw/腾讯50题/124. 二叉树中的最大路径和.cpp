#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
class Solution {
public:
    int res=INT_MIN;
    int maxPathSum(TreeNode* root) {
        helper(root);
        return res;
    }
    int helper(TreeNode*root){
        if(!root)return 0;
        int left=0,right=0,cur=root->val;
        if(root->left){
            left=helper(root->left);
            if(left>0)cur+=left;
        }
        if(root->right){
            right=helper(root->right);
            if(right>0)cur+=right;
        }
        res=max(res,cur);
        cur=max(left,right);
        return cur>0?(root->val+cur):root->val;
    }
};