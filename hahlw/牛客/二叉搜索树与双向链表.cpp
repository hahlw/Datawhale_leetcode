#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};
class Solution {
public:
    TreeNode* pre = nullptr;
    TreeNode* head = nullptr;
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        helper(pRootOfTree);
        return head;
    }
    void helper(TreeNode*root){
        if(!root)
            return ;
        helper(root->left);
        if(!pre){
            head = root;
            pre = root;
        }
        else{
            root->left = pre;
            pre->right = root;
            pre = root;
        }
        helper(root->right);
    }
};