/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
vector<int> inorderTraversal(TreeNode* root) {
        
   TreeNode *p = root;
   vector<int> res;
   if(!p)
   {
	   return res;
   }

   stack<TreeNode *> s;

   while(true)
   {
	   while(p!=NULL)
	   {
		   s.push(p);
		   p = p->left;
	   }

	   if(s.empty())
	   {
		   return res;
	   }

	   p = s.top();
	   res.push_back(p->val);
	   s.pop();

	   p = p->right;
   }
}

};

