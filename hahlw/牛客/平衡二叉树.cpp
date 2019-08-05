#include<iostream>
using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x):val(x),left(NULL), right(NULL) {}
};

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        if(!pRoot)
            return true;
        int left=depth(pRoot->left);
        int right = depth(pRoot->right);
        return abs(left - right) <= 1 && IsBalanced_Solution(pRoot->left) 
                                      && IsBalanced_Solution(pRoot->right);
    }
    int depth(TreeNode*root){
        if(!root)return 0;
        return max(depth(root->left),depth(root->right))+1;
    }
};

class Solution1 {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return depth(pRoot) != -1;
    }

    int depth(TreeNode*root){
        if(!root)return 0;
        int left = depth(root->left);
        if(left==-1)return -1;
        int right = depth(root->right);
        if(right==-1)return -1;
        return abs(left - right) > 1 ? -1 : max(left, right) + 1;
    }
};



