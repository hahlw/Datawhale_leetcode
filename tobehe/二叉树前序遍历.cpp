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
    vector<int> preorderTraversal(TreeNode* root) {
    TreeNode *p = root;
	vector<int> res;
	if (p == NULL)
	{
		return res;
	}

	stack<TreeNode *>s;


	while (true)
	{
		while(p != NULL)
		{
			res.push_back(p->val);
			s.push(p);
            p=p->left;
		}

		if (s.empty())
		{
			return res;
		}

		p = s.top();
		s.pop();
		
		p = p->right;

	}
    }
};