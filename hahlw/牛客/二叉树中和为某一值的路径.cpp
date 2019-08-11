#include<iostream>
#include<vector>
#include<algorithm>
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
    bool cmp(const vector<int>&a,const vector<int>&b){
        return a.size() > b.size();
    }
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int>> res;
        vector<int> cur;
        if(!root)
            return res;
        helper(res, cur, root, expectNumber);
        sort(res.begin(), res.end(), cmp);
        return res;
    }
    void helper( vector<vector<int>> &res,vector<int>&cur,TreeNode*root,int expectNumber){
        if(!root->left&&!root->right){
            if(expectNumber==root->val){
                cur.push_back(root->val);
                res.push_back(cur);
                cur.pop_back();
            }
            return;
        }
        cur.push_back(root->val);
        if(root->left)helper(res, cur, root->left, expectNumber-root->val);
        if(root->right)helper(res, cur, root->right, expectNumber-root->val);
        cur.pop_back();
    }
};