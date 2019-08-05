/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//递归的很巧妙的运用！
//忽然觉得之前的都忘记了啊！
class Solution {
public:
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot == NULL) return 0;
        
        int left = TreeDepth(pRoot->left);
        int right = TreeDepth(pRoot->right);
        
        return (left>right)?(left+1):(right+1);
    }
};
