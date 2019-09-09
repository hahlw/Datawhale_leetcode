#include <iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int leftN=findChild(root->left);
        if(leftN+1==k)return root->val;
        else if(k<=leftN)return kthSmallest(root->left,k);
        else return kthSmallest(root->right,k-leftN-1);
    }
    int findChild(TreeNode*root){
        if(!root)return 0;
        return findChild(root->left)+findChild(root->right)+1;
    }
};