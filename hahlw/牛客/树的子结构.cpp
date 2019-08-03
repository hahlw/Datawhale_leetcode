/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if (!pRoot1 || !pRoot2)
            return false;
        return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
    }
    bool isSubtree(TreeNode* A, TreeNode* B)
    {
        if (!B)
            return true;
        if (!A)
            return false;
        if (A->val == B->val) {
            return isSubtree(A->left, B->left) && isSubtree(A->right, B->right);
        } else
            return false;
    }
};